cmake_minimum_required (VERSION 3.10)

project (Battleship VERSION 1.0)

configure_file(BattleshipConfig.h.in BattleshipConfig.h)

set(SOURCES judge.cpp player.cpp console.h socket.h socket.cpp)

add_executable(judge judge.cpp config.h socket.h socket.cpp)
add_executable(player player.cpp console.h config.h socket.h socket.cpp)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
