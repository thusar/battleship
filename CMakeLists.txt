cmake_minimum_required (VERSION 3.22)

include_directories(./include)

project(Test4 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(client_main ./src/client_main.cpp ./src/client.cpp)

add_executable(server_main ./src/server_main.cpp ./src/server.cpp)