#include "include/board.hpp"
#include <iostream>

Board::Board() {
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            board[x][y] = '~';
        }
    }
}