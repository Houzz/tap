/*
Copyright 2017 Houzz, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "db/db.h"
#include "util/tap_context.h"
#include <sqlite3.h>
#include <folly/String.h>
#include <glog/logging.h>

using namespace std;

namespace Tap {

static void runSqlHelper(sqlite3* db, const string& sql) {
  char *errMsg = 0;
  if (sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg) != SQLITE_OK) {
    LOG(ERROR) << "Sqlite Error: " << errMsg << " query:" << sql;
  }
}

DB& DB::getInstance() {
  static DB instance;
  return instance;
}

DB::DB() {
  string dbFilename = TapContext::getInstance().getDBFile();
  if (sqlite3_open(dbFilename.c_str(), &m_db) != SQLITE_OK) {
    string msg(sqlite3_errmsg(m_db));
    LOG(FATAL) << "Failed to open sqlite db, error message:" << msg;
    return;
  }
  string sql = "CREATE TABLE IF NOT EXISTS error (filename TEXT, " \
    "type_id INT, type_text TEXT, line0 INT, char0 INT, line1 INT, char1 INT, message TEXT);";
  runSqlHelper(m_db, sql);
  sql = "CREATE INDEX IF NOT EXISTS filename ON error (filename);";
  runSqlHelper(m_db, sql);
  sql = "CREATE TABLE IF NOT EXISTS meta (key STRING PRIMARY KEY, value STRING);";
  runSqlHelper(m_db, sql);
  sql = "CREATE TABLE IF NOT EXISTS stats (name TEXT, error_count INT, warning_count INT);";
  runSqlHelper(m_db, sql);
  sql = "CREATE INDEX IF NOT EXISTS name ON stats (name);";
  runSqlHelper(m_db, sql);
}

DB::~DB() {
  sqlite3_close(m_db);
}

void DB::runSql(const string& sql) {
  if (m_db) runSqlHelper(m_db, sql);
}

void DB::clear() {
  if (!m_db) return;
  runSqlHelper(m_db, "DELETE FROM error;");
}

void DB::clearFileError(const string& filename) {
  if (!m_db) return;
  string sql = "DELETE FROM error WHERE filename = \"" + filename + "\";";
  runSqlHelper(m_db, sql);
}

static int s_status = 0;

static int callback(void *notUsed, int argc, char **argv, char **name) {
  for (int i = 0 ; i < argc ; ++i) {
    if (strcmp(name[i], "value") == 0) {
      sscanf(argv[i], "%d", &s_status);
    }
  }
  return 0;
}

DB::ServerStatus DB::getServerStatus() {
  if (!m_db) return ServerStatus::STOPPED;
  string sql = "SELECT value FROM meta WHERE key = 'status';";
  char *errMsg = 0;
  sqlite3_exec(m_db, sql.c_str(), callback, 0, &errMsg);
  return static_cast<ServerStatus>(s_status);
}

void DB::setServerStatus(DB::ServerStatus status) {
  if (!m_db) return;
  string sql = folly::stringPrintf("INSERT OR REPLACE INTO meta (key, value) VALUES ('status', '%d');", status);
  runSqlHelper(m_db, sql);
}


static int callbackForGetErrors(void *notUsed, int argc, char **argv, char **colName) {
  char filename[256];
  char message[65536];
  char errorTypeStr[128];
  int line0, line1, char0, char1, errorCode;
  for (int i = 0 ; i < argc ; ++i) {
    if (strcmp(colName[i], "filename") == 0) {
      strcpy(filename, argv[i]);
    } else if (strcmp(colName[i], "type_id") == 0) {
      sscanf(argv[i], "%d", &errorCode);
    } else if (strcmp(colName[i], "type_text") == 0) {
      strcpy(errorTypeStr, argv[i]);
    } else if (strcmp(colName[i], "line0") == 0) {
      sscanf(argv[i], "%d", &line0);
    } else if (strcmp(colName[i], "char0") == 0) {
      sscanf(argv[i], "%d", &char0);
    } else if (strcmp(colName[i], "line1") == 0) {
      sscanf(argv[i], "%d", &line1);
    } else if (strcmp(colName[i], "char1") == 0) {
      sscanf(argv[i], "%d", &char1);
    } else if (strcmp(colName[i], "message") == 0) {
      strcpy(message, argv[i]);
    }
  }
  printf("[%s] %s[%d:%d - %d:%d] %s\n", errorTypeStr, filename, line0, char0, line1, char1, message);  
  return 0;
}

void DB::getErrors(const char* filename) {
  char *errMsg = 0;
  char cmd[1010];
  snprintf(cmd, 1000, "SELECT * FROM error WHERE filename like '%s%%';", filename);
  if (sqlite3_exec(m_db, cmd, callbackForGetErrors, 0, &errMsg)) {
    fprintf(stderr, "SQL Error: %s\n", errMsg);
    sqlite3_free(errMsg);
  }
}

}
