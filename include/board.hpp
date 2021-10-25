#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include <vector>
#include <string>
#include <iostream>
#include <map>

// VIEW HELPER

class Board {
    // int* ptr;
    public:
        Board();
        char board[10][10];
        void initializeBoard(Board &b);
        void printBoard(bool isPlayer);
        std::map<const std::pair<int, int>, bool> positions;

        // Board(int* ptr) : ptr(ptr) {}
        // int* operator[](const int x) {return x + x;}

    private:
};

#endif