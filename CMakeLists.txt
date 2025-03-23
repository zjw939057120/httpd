cmake_minimum_required(VERSION 3.19)
project(httpd)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-D_DEBUG_ENV)

include_directories(Inc)
include_directories(3rdparty/include)
include_directories(3rdparty/include/hv)
link_directories(3rdparty/lib)

link_libraries(
        -lhv_static
        -lsqlite3
        -lwinmm
        -lws2_32
        -lsecur32
        -lcrypt32
)

file(GLOB INCLUDE "Inc/*.h")
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} httpd.cpp ${INCLUDE} ${SOURCES})

add_executable(http_server http_server_test.cpp)

add_executable(http_client http_client_test.cpp)
