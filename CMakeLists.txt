cmake_minimum_required (VERSION 3.16)

project (Battleship VERSION 1.0)

configure_file(BattleshipConfig.h.in BattleshipConfig.h)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)

add_executable(judge ${PROJECT_SOURCE_DIR}/src/judge.cpp)
              
add_executable(player ${PROJECT_SOURCE_DIR}/src/player.cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
