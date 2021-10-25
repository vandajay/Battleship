#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "board.hpp"

class Game {
    public:
        void startGame();
        void printBoard(Board &b);
        std::pair<int, int> getPlayerCoord();
        bool getPlayerVertical();
        bool setPlayerShip(int ship, bool vertical, std::pair<int, int> coord);



    private:
};

#endif