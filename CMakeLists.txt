cmake_minimum_required(VERSION 3.19)
project(httpd)

set(CMAKE_CXX_STANDARD 14)

# 开启静态编译
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

option(DEBUG_MODE "Enable DEBUG_MODE" ON)
if(DEBUG_MODE)
    add_definitions(-DDEBUG_MODE)
    message("DEBUG_MODE is enabled")
else()
    message("DEBUG_MODE is disabled")
endif()

include_directories(Inc)
include_directories(3rdparty/include)
include_directories(3rdparty/include/hv)
link_directories(3rdparty/lib)

link_libraries(
        -lhv_static
        -lsqlite3
        -ljsoncpp
        -lwinmm
        -lws2_32
        -lsecur32
        -lcrypt32
)

file(GLOB INCLUDE "Inc/*.h")
file(GLOB SOURCES "src/*.cpp")

if(DEBUG_MODE)
    add_executable(${PROJECT_NAME} httpd.cpp ${INCLUDE} ${SOURCES})
else()
    add_executable(${PROJECT_NAME} WIN32 httpd.cpp ${INCLUDE} ${SOURCES})
endif()

add_executable(http_server http_server_test.cpp)

add_executable(http_client http_client_test.cpp)
