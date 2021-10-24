#ifndef __BOARD_HPP__
#define __BOARD_HPP__

// #include "include/game.hpp"
#include "ship.hpp"
// #include "include/board.hpp"

#include <vector>
#include <string>

// VIEW HELPER

class Board {
    public:
        Board();
        ~Board();

        carrier* cShip;
        battleship* bShip;
        patrol* pShip;
        submarine* sShip;
        destroyer* dShip;

        enum class STATE {
            HIT, MISS, EMPTY
        };

        char player[10][10];
        char enemy[10][10];
        void initializeBoards();
        void printBoard(bool isPlayer);

    private:
};

#endif