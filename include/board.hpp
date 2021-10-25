#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <string>
#include <iostream>

// VIEW HELPER

class Board {
    // int* ptr;
    public:
        Board();
        char board[10][10];
        void initializeBoard(Board &b);
        void printBoard(bool isPlayer);

        // Board(int* ptr) : ptr(ptr) {}
        // int* operator[](const int x) {return x + x;}

    private:
};

#endif