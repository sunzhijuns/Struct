cmake_minimum_required(VERSION 3.9)
project(Struct)

set(CMAKE_CXX_STANDARD 11)


message(status " Struct : this is binary dir " ${STRUCT_BINARY_DIR})
message(status " Struct : this is binary dir " ${PROJECT_BINARY_DIR})
message(status " Struct : this is source dir " ${STRUCT_SOURCE_DIR})
message(status " Struct : this is source dir " ${PROJECT_SOURCE_DIR})

ADD_SUBDIRECTORY(src bin)
#
#INSTALL(FILES COPYRIGHT README DESTINATION temp_bin/struct)
#INSTALL(PROGRAMS run_struct.sh DESTINATION bin)
#
#INSTALL(DIRECTORY doc/ DESTINATION temp_bin/struct)


