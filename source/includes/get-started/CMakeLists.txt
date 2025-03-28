# start-configure
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(c-quickstart LANGUAGES C)
add_executable (quickstart.out quickstart.c)
# end-configure
# start-libmongoc
find_package(mongoc {+full-version+} REQUIRED)
target_link_libraries(quickstart.out mongoc::mongoc)
# end-libmongoc