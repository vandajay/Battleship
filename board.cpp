#include "include/game.hpp"
#include "include/ship.hpp"
#include "include/board.hpp"

#include <iostream>

Board::Board() {
    Board::initializeBoards();

}

void Board::initializeBoards() {
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            player[x][y] = '~';
            enemy[x][y] = '~';
        }
    }
}

Board::~Board() {}

void Board::printBoard(bool isPlayer) {
    int width = 10;
    std::cout << " 0123456789" << std::endl;

    for (int y = 0; y < width; ++y) {
        std::cout << y;
        for (int x = 0; x < width; ++x) {
            if (isPlayer){
                std::cout << this->player[x][y];
            } else {
                std::cout << this->enemy[x][y];
            }
            if (x == width - 1)
                std::cout << std::endl;
        }
    }
}