#include <iostream>
#include <mutex>
#include <string>
#include <thread>

#include "board.h"
#include "socket.h"

// std::mutex lock;

class Player 
{
private:
    std::array<std::array<char, 10>, 10> _playerHits;

public:
    std::array<std::array<char, 10>, 10> GetPlayerHits() { return _playerHits; }
};

int main(int argc, char* argv[]) 
{
    constexpr int port {8080};
    const std::string localhost {"127.0.0.1"};

    return 0;
}


    
