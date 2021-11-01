#include "Game.hpp"
#include <iostream>
#include <cstdlib>

// std::ostream& operator << (std::ostream& output, Board& b) {
//     output << "  A B C D E F G H I J\n";
//     for (int y = 0; y < BOARD_DIM; ++y) {
//         output << y << " ";
//         for (int x = 0; x < BOARD_DIM; ++x)
//             std::cout << b.gameBoard[y][x] << " ";
//         output << std::endl;
//     }

//     return output;
// }

void Game::startGame() {
    playerBoard = new Board();
    enemyBoard = new Board();
    initializeBoard();
    initializeBoardAuto();
}

bool Game::playGame() {
    startGame();
    while(gameCondition() == UNFINISHED) {
        printGameState();
        getNextMove();
        getNextMoveAuto();
        printGameState();
    }

    if (gameCondition() == PLAYER_WIN)
        std::cout << "Player wins!" << std::endl;
    else
        std::cout << "Enemy wins!" << std::endl;
    
    return true;
}

void Game::initializeBoard() {
    int xEntry, yEntry, horizEntry, attemptCount;
    std::string entryTemp;
    for (int i = 0; i < NUM_SHIPS; i++) 	{
        attemptCount = 0;
        do // check for valid placement of each ship
        {
            playerBoard->printPublicBoard();
            if (attemptCount > 0)
                std::cout << "INVALID ENTRY for that ship! Please try again. \n";

            std::cout << "Please enter location [Letter][Number] for the top/left of your " << SHIP_NAMES[i] << " which is length " << SHIP_LENGTHS[i] << ": \n";
            entryTemp = getSquare();
            xEntry = static_cast<int>(entryTemp[0]);
            yEntry = static_cast<int>(entryTemp[1]);

            std::cout << "Please enter 0 if the ship is oriented vertically, "
                << "1 if it is oriented horizontally:\n";
            std::cin >> horizEntry;

            attemptCount++;
        } while (!playerBoard->placeShip(i, xEntry - LETTER_CHAR_OFFSET,
            yEntry - NUMBER_CHAR_OFFSET, horizEntry));

    }

    std::cout << "Your starting board:" << std::endl;
    playerBoard->printPublicBoard();
}

void Game::initializeBoardAuto() {
    int xEntry, yEntry, horizEntry;

    for (int i = 0; i < NUM_SHIPS; i++) {
        do // randomize position placements and place ships if possible
        {
            xEntry = rand() % 10;
            yEntry = rand() % 10;
            horizEntry = rand() % 2;
        } while (!enemyBoard->placeShip(i, xEntry, yEntry, horizEntry));

    }
}

state Game::gameCondition() {
    if (playerBoard->getNumHits() == TOTAL_SHIP_SPACES)
        return PLAYER_WIN;
    else if (enemyBoard->getNumHits() == TOTAL_SHIP_SPACES)
        return ENEMY_WIN;
    else
        return UNFINISHED;
}

void Game::printGameState() {
    std::cout << "ENEMY BOARD: \n";
    enemyBoard->printPrivateBoard();
    std::cout << "PLAYER BOARD: \n";
    playerBoard->printPublicBoard();
    std::cout << std::endl << std::endl;
}

void Game::getNextMove() {
    int attemptCount = 0;
    int xEntry, yEntry;
    bool goodMove = false;
    std::string entryTemp;

    while (!goodMove) {
        if (attemptCount > 0)
            std::cout << "That move has already been attempted. Try again. \n";

        std::cout << "Please enter location [Letter][Number] of desired move:\n";
        entryTemp = getSquare();
        xEntry = static_cast<int>(entryTemp[0]);
        yEntry = static_cast<int>(entryTemp[1]);

        if (playerBoard->getSpaceValue(xEntry - LETTER_CHAR_OFFSET,
            yEntry - NUMBER_CHAR_OFFSET) != isHIT
            && playerBoard->getSpaceValue(xEntry - LETTER_CHAR_OFFSET,
                yEntry - NUMBER_CHAR_OFFSET) != isMISS) {
            playerBoard->recordHit(xEntry - LETTER_CHAR_OFFSET, yEntry - NUMBER_CHAR_OFFSET);
            goodMove = true;
        }
        attemptCount++;
    }

    return;
}
void Game::getNextMoveAuto() {
    bool goodMove = false;
    int xEntry, yEntry;

    while (!goodMove) 	{
        // randomly choose next move
        xEntry = rand() % 10;
        yEntry = rand() % 10;

        if (enemyBoard->getSpaceValue(xEntry, yEntry) != isHIT
            && enemyBoard->getSpaceValue(xEntry, yEntry) != isMISS) {
            enemyBoard->recordHit(xEntry, yEntry);
            goodMove = true;
        }
    }
}

std::string Game::getSquare() {
    std::string retString;
    std::getline(std::cin, retString);
    bool isGoodInput = false;

    while (!isGoodInput) {
        // check for two character entries of letter/number
        if (retString.length() == 2 && (retString[0] >= 65 && retString[0] <= 74)
            && (retString[1] >= 48 && retString[1] <= 57))
            isGoodInput = true;
        else 		{
            std::cout << "Bad input! Please enter location [Letter][Number] of "
                << "your desired move, with capital letters only:\n";
            std::getline(std::cin, retString);
        }
    }
    return retString;
}

int main(int argc, char** argv) {
    Game battleship;
    battleship.playGame();
    return 0;
}

// int getInt(int min, int max) {
//     std::string retString;
//     std::getline(std::cin, retString);
//     bool isGoodInput = false;
//     int nIter = 0;
//     char tempChar;
//     bool isNeg = false;
//     int retInt = 0;

//     while (!isGoodInput) 	{
//         isGoodInput = true;
//         // prompt fot input again if input was bad
//         if (nIter > 0) 		{
//             std::cout << "Bad input! Please enter an integer between " << min;
//             std::cout << " and " << max << "." << std::endl;
//             std::getline(std::cin, retString);
//         }
//         if (retString.length() > 0) 		{
//             // process the string, char by char, to see if it's a numeric
//             for (int i = 0; i < retString.length(); i++) 			{
//                 tempChar = static_cast<char>(retString[i]);
//                 // if the first character is a negatve, note it, and continue
//                 if (i == 0 & tempChar == '-') 				{
//                     isNeg = true;
//                 }
//                 // if char is numeric, update the integer to be returned
//                 else 				{
//                     if (tempChar >= ASCII_INT_MIN && tempChar <= ASCII_INT_MAX) 					{
//                         retInt = retInt * 10 + (static_cast<int>(tempChar) -
//                             ASCII_INT_MIN);
//                     }
//                     else // if any non-ints encountered, break loop
//                     {
//                         isGoodInput = false;
//                         break;
//                     }
//                 }
//             }
//         }
//         // zero length inputs are bad inputs
//         else 		{
//             isGoodInput = false;
//         }

//         // if negative, mutiply by -1
//         if (isGoodInput && isNeg) 		{
//             retInt = (-1) * retInt;
//         }
//         // check that int is between limits
//         if (isGoodInput && (retInt<min || retInt>max)) 		{
//             isGoodInput = false;
//         }

//         // if input was bad, reset trackers and start over again
//         if (!isGoodInput) 		{
//             retInt = 0;
//             isNeg = false;
//         }

//         nIter++;
//     }

//     return retInt;
// }