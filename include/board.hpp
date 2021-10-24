#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <string>

// VIEW HELPER

class Board {
    public:
        Board();
        ~Board();

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