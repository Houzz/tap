cmake_minimum_required(VERSION 3.6)
project(tap VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(Boost_USE_STATIC_LIBS ON)
set(CMAKE_FIND_LIBRARY_SUFFIXES .a)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Glog)
find_package(RapidJSON)
find_package(SQLite3)
#find_package(Gflags COMPONENTS nothreads_static)

find_library(GFLAGS_STATIC_LIBRARY gflags)
message("found gflags static library ${GFLAGS_STATIC_LIBRARY}")
find_library(GLOG_STATIC_LIBRARY glog PATHS "/usr/local/lib/")
message("found glog static library ${GLOG_STATIC_LIBRARY}")
find_library(FOLLY_STATIC_LIBRARY folly)
message("found folly static library ${FOLLY_STATIC_LIBRARY}")
find_library(SQLITE3_STATIC_LIBRARY sqlite3 PATHS "/usr/local/Cellar/sqlite/*/lib/")
message("found sqlite3 static library ${SQLITE3_STATIC_LIBRARY}")
find_library(FSWATCH_STATIC_LIBRARY fswatch)
find_path(FSWATCH_INCLUDE_DIR monitor.hpp PATHS "/usr/local/include/libfswatch/c++/") 
message("found fswatch static library ${FSWATCH_STATIC_LIBRARY}, include path ${FSWATCH_INCLUDE_DIR}")

include_directories("${Boost_INCLUDE_DIRS}")
include_directories("${GLOG_INCLUDE_DIRS}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${SQLITE3_INCLUDE_DIR}")
include_directories("${FSWATCH_INCLUDE_DIR}")

add_subdirectory(ast)
add_subdirectory(type)
add_subdirectory(entity)
add_subdirectory(visitor)
add_subdirectory(util)
add_subdirectory(parser)
add_subdirectory(db)
add_subdirectory(server)

add_executable(tap_server server_main.cpp)
add_executable(tap_client client_main.cpp)

target_link_libraries(tap_server db server ast entity type visitor util parser
    ${Boost_LIBRARIES} ${SQLITE3_STATIC_LIBRARY} ${FOLLY_STATIC_LIBRARY}
    -ldouble-conversion ${FSWATCH_STATIC_LIBRARY} ${GLOG_STATIC_LIBRARY} ${GFLAGS_STATIC_LIBRARY}
    -pthread -ldl
)
target_link_libraries(tap_client db ${SQLITE3_STATIC_LIBRARY} ${FOLLY_STATIC_LIBRARY}
    -ldouble-conversion ${FSWATCH_STATIC_LIBRARY} -pthread -ldl ${GLOG_STATIC_LIBRARY} ${GFLAGS_STATIC_LIBRARY}
)
