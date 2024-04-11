#include <iostream>
#include <string>

#include "board.h"
#include "socket.h"

class Judge 
{
private:
    std::array<std::array<char, 10>, 10> _firstArmada;
    std::array<std::array<char, 10>, 10> _secondArmada;
public:
    Judge() = default;
    ~Judge() = default;
    friend class Board;
    std::array<std::array<char, 10>, 10> GetFirstArmada() { return _firstArmada; }
    std::array<std::array<char, 10>, 10> GetSecondArmada() { return _secondArmada; }
};

int main(int argc, char* argv[])
{
    const int port = 8080;
    std::string ipaddr = "0.0.0.0";
    Judge judge;

    return 0;
}