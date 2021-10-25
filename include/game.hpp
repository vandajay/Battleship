#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "board.hpp"

#include <map>

class Game {
    public:
        void startGame();
        void printBoard(Board &b);
        std::pair<int, int> getPlayerCoord();
        bool getPlayerVertical();
        bool setPlayerShip(int ship);
        bool checkCoord(Board &b, int ship, bool isVertical, std::pair<int, int> coord);





    private:
};

#endif