#include "Board.hpp"

/***********************************************************************
 * An attempt at overloading the stream operator for the purpose of
 * passing only a board to std::cout for printing.
 * @return std::ostream&
 **********************************************************************/
// std::ostream& operator << (std::ostream& output, Board& b) {
//     output << "  A B C D E F G H I J" << std::endl;
//     for (int y = 0; y < BOARD_DIM; ++y) {
//         output << y << " ";
//         for (int x = 0; x < BOARD_DIM; ++x)
//             output << b.this->board[y][x] << std::endl;
//         // output << std::endl;
//     }
//     return output;
// }

/***********************************************************************
 * Default constructor that initializes an empty board of water, and 
 * initializes the boards this->shipVector.
 * @param none
 **********************************************************************/
Board::Board() {
    for (int y = 0; y < BOARD_DIM; ++y)
        for (int x = 0; x < BOARD_DIM; ++x)
            this->board[y][x] = isWATER;

    // initialize ships into vector of ships
    for (int i = 0; i < NUM_SHIPS; ++i)
        this->shipVector.push_back(Ship(SHIP_LENGTHS[i], SHIP_NAMES[i])); 
}

/***********************************************************************
 * Determines the number of current hits to a boards ships.
 * @return int hits to boards ships (0<=17)
 **********************************************************************/
int Board::getNumHits() {
    int count = 0;

    for (int i = 0; i < BOARD_DIM; ++i)
        for (int x = 0; x < BOARD_DIM; ++x)
            if (this->board[i][x] == isHIT)
                count++;
    return count;
}

/***********************************************************************
 * Prints a board with "fog of war", used for enemy board.
 * @return none
 **********************************************************************/
void Board::printPrivateBoard() {
    std::cout << "  A B C D E F G H I J" << std::endl;
    for (int y = 0; y < BOARD_DIM; ++y) {
        std::cout << y << " ";
        for (int x = 0; x < BOARD_DIM; ++x) {
            if (this->board[y][x] == isHIT || this->board[y][x] == isMISS)
                std::cout << this->board[y][x] << " ";
            else // fog-o-war
                std::cout << isFOG << " ";
        }
        std::cout << std::endl;
    }
}

/***********************************************************************
 * Prints a board with ships visible, used for player board.
 * @return none
 **********************************************************************/
void Board::printPublicBoard() {
    std::cout << "  A B C D E F G H I J" << std::endl;
    for (int y = 0; y < BOARD_DIM; ++y) {
        std::cout << y << " ";
        for (int x = 0; x < BOARD_DIM; ++x)
            std::cout << this->board[y][x] << " ";
        std::cout << std::endl;
    }
    // std::cout << "  A B C D E F G H I J" << std::endl;
    // for(int i = 0; i < 100; ++i) {
    //     if(i % 10 == 0)
    //         std::cout << i / 10;
    //     std::cout << *(this->board) << std::endl;
    // }
}

/***********************************************************************
 * Getter function for retrieving the current value for a cell.
 * @param int x x coordinate for a cell, [A-J] on board
 * @param int y y coordinate for a cell, [0-9] on board
 * @return char the state of the cell
 **********************************************************************/
char Board::getCellState(int x, int y) {
    return this->board[y][x];
}

/***********************************************************************
 * Setter function for recording hits to board and ship.
 * @param int x x coordinate for a target cell, [A-J] on board
 * @param int y y coordinate for a target cell, [0-9] on board
 * @return bool true on a successful hit, false for a miss
 **********************************************************************/
bool Board::setHit(int x, int y) {
    for (int i = 0; i < NUM_SHIPS; ++i) {
        if (this->shipVector[i].setHit(x, y)) {
            // update board with hit
            this->board[y][x] = isHIT;
            // text confirmation if sink
            if (this->shipVector[i].isShipSunk())
                std::cout << std::endl << "** You sunk the " << this->shipVector[i].getName() << "! **" << std::endl;
            return true;
        }
    }
    this->board[y][x] = isMISS;
    return false;
}

/***********************************************************************
 * Setter function for placing ships during game initialization.
 * @param int shipNum number corresponds to what type of ship is being
 * placed, 0=carrier...4=destroyer.
 * @param int x x coordinate for a cell, [A-J] on board
 * @param int y y coordinate for a cell, [0-9] on board
 * @param bool h 1 for horizontal, 0 for vertical placement
 * @return bool true on a successful hit, false for a miss
 **********************************************************************/
bool Board::placeShip(int shipNum, int x, int y, bool h) {
    //if x or y is out of bounds, return false
    if (y >= BOARD_DIM || x >= BOARD_DIM)
        return false;

    // ship already placed
    if (this->shipVector[shipNum].getX() >= 0 && this->shipVector[shipNum].getY() >= 0)
        return false;

    // check required cells for ship
    for (int i = 0; i < this->shipVector[shipNum].getSize(); ++i) {
        // check if any cells are filled
        if ((h && this->board[y][x + i] != isWATER) ||
            (!h && this->board[y + i][x] != isWATER))
            return false;
        // check for out of bounds
        if ((h && (x + i) >= BOARD_DIM) ||
            (!h && (y + i) >= BOARD_DIM))
            return false;
    }

    // place ship
    for (int i = 0; i < this->shipVector[shipNum].getSize(); ++i) {
        if (h)
            this->board[y][x + i] = isSHIP;
        else
            this->board[y + i][x] = isSHIP;
    }

    // set ship object 
    this->shipVector[shipNum].setPosition(x, y, h);

    return true; // on successful ship placment
}