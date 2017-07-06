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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#include <sqlite3.h>
#include "db/db.h"

#define SERVER_PATH "/houzz/c2svc/src/cpp/tap/build/tap_server"

void forkServer() {
  if (fork() == 0) {
    // child process: tap server
    if (execlp(SERVER_PATH, "tap_server", 0))
      printf("execlp error\n");
  }
}

void waitUntilRunning() {
  while (Tap::DB::getInstance().getServerStatus() != Tap::DB::ServerStatus::RUNNING) {
    printf("Waiting for status becoming 'running'...\n");
    sleep(1);
  }
}

void stopServer() {
  FILE *fp = fopen("/tmp/tap.pid", "r");
  int serverPid;
  if (!fp || fscanf(fp, "%d", &serverPid) != 1) {
    printf("Failed to find server process id\n");
    exit(1);
  }
  if (kill(serverPid, SIGTERM)) {
    printf("Failed to send SIGTERM to server process\n");
    exit(1);
  }
}

int main(int argc, char **argv) {
  char dirToCheck[100] = {0};
  if (argc >= 2) {
    if (strcmp(argv[1], "status") == 0) {
      Tap::DB::ServerStatus status = Tap::DB::getInstance().getServerStatus();
      switch (status) {
        case Tap::DB::ServerStatus::INIT:
          printf("Tap server status: initializing\n");
          break;
        case Tap::DB::ServerStatus::RUNNING:
          printf("Tap server status: running\n");
          break;
        case Tap::DB::ServerStatus::STOPPED:
          printf("Tap server status: stopped\n");
          break;
      }
      exit(0);
    } else if (strcmp(argv[1], "stop") == 0) {
      stopServer();
      exit(0);
    } else if (strcmp(argv[1], "restart") == 0) {
      stopServer();
      if (argc >= 3) {
        strcpy(dirToCheck, argv[2]);
      }
      sleep(2);
      // fall through
    } else if (strcmp(argv[1], "start") == 0) {
      if (argc >= 3) {
        strcpy(dirToCheck, argv[2]);
      }
      // fall through
    } else {
      strcpy(dirToCheck, argv[1]);
    }
  }
  
  Tap::DB::ServerStatus status = Tap::DB::getInstance().getServerStatus();
  if (status == Tap::DB::ServerStatus::STOPPED) {
    printf("Tap server hasn't started. Starting...\n");
    forkServer();
  }
  waitUntilRunning();
  printf("Tap server is running now.\n");
  Tap::DB::getInstance().getErrors(dirToCheck);
  return 0;
}
