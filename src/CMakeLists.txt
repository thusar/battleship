cmake_minimum_required (VERSION 3.22)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_sources(server FILES server.cpp server_main.cpp)

target_sources(client FILES client.cpp client_main.cpp)

add_executable(server_main server.cpp server_main.cpp)

add_executable(client client.cpp client_main.cpp)