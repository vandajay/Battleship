#ifndef __CONSTANTS_HPP__
#define __CONSTANTS_HPP__

#include <string>

const int NUM_SHIPS = 5;
const int BOARD_DIM = 10;
const int BOARD_SPACES = BOARD_DIM * BOARD_DIM;
const int SHIP_LENGTHS[NUM_SHIPS] = { 5, 4, 3, 3, 2 };
const int TOTAL_SHIP_SPACES = 17;
const std::string SHIP_NAMES[NUM_SHIPS] = {
    "CARRIER",
    "BATTLESHIP",
    "CRUISER",
    "SUBMARINE",
    "DESTROYER"
    };

// board value constants
const char isHIT = 'X';
const char isMISS = 'O';
const char isWATER = '~';
const char isSAFESHIP = '#';
const char isUNKNOWN = '?';

// to convert char to board position
const int ASCII_CHAR_MIN = 65;

// consts for input validation
const int ASCII_INT_MIN = 48;
const int ASCII_INT_MAX = 57;

#endif