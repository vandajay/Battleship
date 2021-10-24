#include "include/boards.hpp"
#include <iostream>

Boards::Boards() {}

Boards::~Boards() {}

void Boards::initializeBoards() {
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            player[x][y] = '~';
            enemy[x][y] = '~';
        }
    }
}

void Boards::printBoard(char board[10][10]) {
    int i = 0;
    std::cout << " 0123456789";

    for(int x = 0; x < 10; ++x) {
        std::cout << x;
        for (int y = 0; y < 10; ++y) {
            std::cout << board[x][y];
        }
    }
}