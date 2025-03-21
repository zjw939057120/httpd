cmake_minimum_required(VERSION 3.19)
project(httpd)

set(CMAKE_CXX_STANDARD 14)

include_directories(3rdparty/include/hv)
link_directories(3rdparty/lib)

link_libraries(
        -lhv_static
        -lwinmm
        -lws2_32
        -lsecur32
        -lcrypt32
)

add_executable(${PROJECT_NAME} httpd.cpp router.cpp handler.cpp)

add_executable(http_server http_server_test.cpp)

add_executable(http_client http_client_test.cpp)
