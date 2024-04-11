#include <array>
#include <iostream>
#include <optional>
#include <string>
#include <vector>


class Board
{
private:
    std::array<std::array<char, 10>, 10> _board;
    static const int CARRIER{5};
    static const int BATTLESHIP{4};
    static const int DESTROYER{3};
    static const int SUBMARINE{3};
    static const int PATROL_BOAT{2};
    std::vector<std::array<std::array<char, 10>, 10>> _armada;
    std::array<std::array<char, 10>, 10> _playerFirstArmada;
    std::array<std::array<char, 10>, 10> _playerSecondArmada;
    std::array<std::array<char, 10>, 10> _playerFirstHits;
    std::array<std::array<char, 10>, 10> _playerSecondHits;
public:
    Board() = default;
    ~Board() = default;
    std::array<std::array<char, 10>, 10> GetBoard()
    {
        return _board;
    }
    std::vector<std::array<std::array<char, 10>, 10>> GetArmada()
    {
        return _armada;
    }
    void CreateBoards()
    {
        GetArmada().emplace_back(_playerFirstArmada);
        GetArmada().emplace_back(_playerSecondArmada);
        GetArmada().emplace_back(_playerFirstHits);
        GetArmada().emplace_back(_playerSecondHits);
    }

    std::array<std::array<char, 10>, 10> GetPlayerFirstArmada() { return _playerFirstArmada; }
    std::array<std::array<char, 10>, 10> GetPlayerSecondArmada() { return _playerSecondArmada; }
    std::array<std::array<char, 10>, 10> GetPlayerFirstHits() { return _playerFirstHits; }
    std::array<std::array<char, 10>, 10> GetPlayerSecondHits() { return _playerSecondHits; }
};

