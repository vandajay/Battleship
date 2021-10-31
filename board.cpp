#include "Board.hpp"
#include <iostream>


std::ostream& operator << (std::ostream& output, Board& b) {
    output << "  A B C D E F G H I J\n";
    for (int y = 0; y < BOARD_DIM; ++y) {
        output << y << " ";
        for (int x = 0; x < BOARD_DIM; ++x)
            output << b.gameBoard[y][x] << " ";
        output << "\n";
    }

    return output;
}
Board::Board() {
    for (int y = 0; y < BOARD_DIM; ++y)
        for (int x = 0; x < BOARD_DIM; ++x)
            gameBoard[y][x] = isWATER;

    for (int i = 0; i < NUM_SHIPS; i++)
        shipVec.push_back(Ship(SHIP_LENGTHS[i], SHIP_NAMES[i]));
}

Board::~Board() { return; }

int Board::getNumHits() {
    int count = 0;

    for (int i = 0; i < BOARD_DIM; i++)
        for (int j = 0; j < BOARD_DIM; j++)
            if (gameBoard[i][j] == isHIT)
                count++;

    return count;
}
void Board::printPrivateBoard() {
    std::cout << "  A B C D E F G H I J\n";
    for (int y = 0; y < BOARD_DIM; ++y) {
        std::cout << y << " ";
        for (int x = 0; x < BOARD_DIM; ++x) {
            if (this->gameBoard[y][x] == isHIT || this->gameBoard[y][x] == isMISS)
                std::cout << this->gameBoard[y][x] << " ";
            else // obfuscate non-hit/miss entries
                std::cout << isUNKNOWN << " ";
        }
        std::cout << std::endl;
    }
}

void Board::printPublicBoard() {
    // std::cout << "  A B C D E F G H I J\n";
    // for (int y = 0; y < BOARD_DIM; ++y) {
    //     std::cout << y << " ";
    //     for (int x = 0; x < BOARD_DIM; ++x)
    //         std::cout << gameBoard[y][x] << " ";
    //     std::cout << std::endl;
    // }
    std::cout << *(gameBoard) << std::endl;
}
char Board::getSpaceValue(int x, int y) {
    return gameBoard[y][x];
}
bool Board::recordHit(int x, int y) {
    for (int i = 0; i < NUM_SHIPS; i++) {
        if (shipVec[i].recordHit(x, y)) {
            gameBoard[y][x] = isHIT; //record the hit on the board
            //tell the user that they sunk a ship
            if (shipVec[i].isShipSunk())
                std::cout << "You sunk the " << shipVec[i].getName() << "!\n";
            return true;
        }
    }
    gameBoard[y][x] = isMISS;
    return false;
}

bool Board::placeShip(int shipNum, int x, int y, bool isHorizontal) {
    //if x or y is out of bounds, return false
    if (x >= BOARD_DIM || y >= BOARD_DIM)
        return false;

    //if ship has already been placed, return false
    if (shipVec[shipNum].getX() >= 0 && shipVec[shipNum].getY() >= 0)
        return false;

    //loop through the positions required for the ship
    for (int i = 0; i < shipVec[shipNum].getSize(); i++) 	{
        //if any of the desired spaces are filled, return false
        if ((isHorizontal && gameBoard[y][x + i] != isWATER) ||
            (!isHorizontal && gameBoard[y + i][x] != isWATER))
            return false;
        //if any of the desired spaces are out of bounds, return false
        if ((isHorizontal && (x + i) >= BOARD_DIM) ||
            (!isHorizontal && (y + i) >= BOARD_DIM))
            return false;
    }

    //if the for loop finishes, and all the positions are empty, 
    //1. place the Ship in the desired position on the board
    for (int i = 0; i < shipVec[shipNum].getSize(); i++) {
        if (isHorizontal)
            gameBoard[y][x + i] = isSAFESHIP;
        else
            gameBoard[y + i][x] = isSAFESHIP;
    }

    //2. set the x/y parameters for the Ship object 
    shipVec[shipNum].setPosition(x, y, isHorizontal);

    //... and return true
    return true;
}