cmake_minimum_required (VERSION 3.10)

project (Battleship VERSION 1.0)

configure_file(BattleshipConfig.h.in BattleshipConfig.h)

add_executable(judge judge.cpp)
add_executable(player player.cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
