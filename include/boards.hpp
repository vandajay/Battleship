#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <string>

// VIEW HELPER

class Boards {
    public:
        Boards();
        ~Boards();

        enum class STATE {
            HIT, MISS, EMPTY
        };

        char player[10][10];
        char enemy[10][10];
        void initializeBoards();
        void printBoard(char board[10][10]);

    private:
};

#endif