#ifndef __CONSTANTS_HPP__
#define __CONSTANTS_HPP__

#include <string>

const int BOARD_DIM = 10;
const int BOARD_SPACES = BOARD_DIM * BOARD_DIM;

const int NUM_SHIPS = 5;
const int SHIP_LENGTHS[NUM_SHIPS] = { 5, 4, 3, 3, 2 };
const int TOTAL_SHIP_SPACES = 17;
const std::string SHIP_NAMES[NUM_SHIPS] = {
    "CARRIER",
    "BATTLESHIP",
    "CRUISER",
    "SUBMARINE",
    "DESTROYER"
};

// input validation
const int ASCII_LETTER_MIN = 65; // 'A'
const int ASCII_NUMBER_MIN = 48; // '0'

// board values
const char isWATER = '~';
const char isSHIP = '#';
const char isFOG = '?';
const char isHIT = 'X';
const char isMISS = 'O';

#endif