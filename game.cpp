#include "Game.hpp"
#include <random>

/***********************************************************************
 * Text based representation of the classic board game Battleship using
 * C++. Designed to be played on the command line.
 * @author Jay Van Dam
 * @version October 2021
 **********************************************************************/

/***********************************************************************
 * Helper function to handle starting of the game and initialize player
 * and enemy boards.
 * @return none
 **********************************************************************/
void Game::startGame() {
    playerBoard = new Board();
    enemyBoard = new Board();
    initializeBoardPlayer();
    initializeBoardBot();
    std::cout << std::endl;
    std::cout << "****************" << std::endl;
    std::cout << "** GAME START **" << std::endl;
    std::cout << "****************" << std::endl;
}

/***********************************************************************
 * Function that drives the game loop and determines whether the game
 * has finished.
 * @return none
 **********************************************************************/
void Game::playGame() {
    startGame();
    while(getWinner() == PENDING) {
        printGameState();
        nextMovePlayer();
        nextMoveBot();
    }

    if (getWinner() == PLAYER_WIN) {
        std::cout << std::endl;
        std::cout << "**************" << std::endl;
        std::cout << "** YOU WIN! **" << std::endl;
        std::cout << "**************" << std::endl;
    } else {
        std::cout << std::endl;
        std::cout << "***************" << std::endl;
        std::cout << "** YOU LOSE. **" << std::endl;
        std::cout << "***************" << std::endl;
    }
}

/***********************************************************************
 * Initializes the players board.
 * @return none
 **********************************************************************/
void Game::initializeBoardPlayer() {
    int xEntry, yEntry, count, horizEntry;
    std::string entryTemp,horizTemp;
    for (int i = 0; i < NUM_SHIPS; ++i) {
        count = 0;
        do // check for valid placement of each ship
        {
            std::cout << std::endl;
            playerBoard->printPublicBoard();
            std::cout << std::endl;
            if (count > 0)
                std::cout << "INVALID ENTRY for that ship! Please try again." << std::endl;

            std::cout << "Placing " << SHIP_NAMES[i] << ", Length " << SHIP_LENGTHS[i] << "..." << std::endl;
            std::cout << "Enter coordinate [A-J][0-9]:" << std::endl;
            entryTemp = getSquare();
            xEntry = static_cast<int>(entryTemp[0]);
            yEntry = static_cast<int>(entryTemp[1]);

            std::cout << "Enter 1 for horizontal, 0 for vertical orientation:" << std::endl;
            
            // need to parse int out of string
            // otherwise getline for coords error in getSquare()
            std::getline(std::cin, horizTemp);
            horizEntry = std::stoi(horizTemp);

            count++;
        } while (!playerBoard->placeShip(i, xEntry - ASCII_LETTER_MIN,
            yEntry - ASCII_NUMBER_MIN, horizEntry));
    }
}

/***********************************************************************
 * Initializes the enemy/cpu board.
 * @return none
 **********************************************************************/
void Game::initializeBoardBot() {
    std::random_device device;
    std::mt19937 gen32(device());
    std::uniform_int_distribution<int> distribution9(0, 9);
    std::uniform_int_distribution<int> distribution1(0, 1);
    int xEntry, yEntry, horizEntry;

    for (int i = 0; i < NUM_SHIPS; ++i) {
        do // randomize position placements and place ships if possible
        {
            xEntry = distribution9(gen32) % 10;
            yEntry = distribution9(gen32) % 10;
            horizEntry = distribution1(gen32) % 2;
        } while (!enemyBoard->placeShip(i, xEntry, yEntry, horizEntry));
    }
}

/***********************************************************************
 * Determines the number of hits player and enemy as scored. Used for
 * @return state the state of the game
 * (PLAYER_WIN, ENEMY_WIN, PENDING)
 **********************************************************************/
state Game::getWinner() {
    if (playerBoard->getNumHits() == TOTAL_SHIP_SPACES)
        return ENEMY_WIN;
    else if (enemyBoard->getNumHits() == TOTAL_SHIP_SPACES)
        return PLAYER_WIN;
    else
        return PENDING;
}

/***********************************************************************
 * Prints the current state of enemy and player boards.
 * @return none
 **********************************************************************/
void Game::printGameState() {
    std::cout << std::endl << "ENEMY BOARD:" << std::endl;
    // enemyBoard->printPublicBoard(); // Used for debugging
    enemyBoard->printPrivateBoard();

    std::cout << std::endl << "PLAYER BOARD:" << std::endl;
    playerBoard->printPublicBoard();
    std::cout << std::endl;
}


/***********************************************************************
 * Determines player/user input to for next move.
 * @return none
 **********************************************************************/
void Game::nextMovePlayer() {
    int cnt = 0;
    int xEntry, yEntry;
    bool valid = false;
    std::string entryTemp;

    while (!valid) {
        if (cnt > 0)
            std::cout << "Move already exists..." << std::endl;

        std::cout << "Enter move [A-J][0-9]:" << std::endl;
        entryTemp = getSquare();
        xEntry = static_cast<int>(entryTemp[0]);
        yEntry = static_cast<int>(entryTemp[1]);

        if (enemyBoard->getCellState(xEntry - ASCII_LETTER_MIN,
            yEntry - ASCII_NUMBER_MIN) != isHIT
            && enemyBoard->getCellState(xEntry - ASCII_LETTER_MIN,
                yEntry - ASCII_NUMBER_MIN) != isMISS) {
            enemyBoard->setHit(xEntry - ASCII_LETTER_MIN, yEntry - ASCII_NUMBER_MIN);
            valid = true;
        }
        cnt++;
    }
}

/***********************************************************************
 * Determines enemy/cpu next move using random number generation.
 * @return none
 **********************************************************************/
void Game::nextMoveBot() {
    std::random_device device;
    std::mt19937 gen32(device());
    std::uniform_int_distribution<int> distribution9(0, 9);
    bool valid = false;
    int xEntry, yEntry;

    while (!valid) 	{
        // randomly choose next move
        xEntry = distribution9(gen32) % 10;
        yEntry = distribution9(gen32) % 10;

        if (playerBoard->getCellState(xEntry, yEntry) != isHIT && playerBoard->getCellState(xEntry, yEntry) != isMISS) {
            playerBoard->setHit(xEntry, yEntry);
            valid = true;
        }
    }
}
/***********************************************************************
 * Determines enemy/cpu next move using random number generation.
 * @return std::string string of user input [A-J][0-9]
 **********************************************************************/
std::string Game::getSquare() {
    std::string playerInput;
    std::getline(std::cin, playerInput);
    bool valid = false;

    while (!valid) {
        /**
         * check for two character entries of letter/number
         * A=65, J=74, 48=0, 9=57
         */
        if (playerInput.length() == 2 && (playerInput[0] >= 65 && playerInput[0] <= 74) && (playerInput[1] >= 48 && playerInput[1] <= 57)) {
            valid = true;
        } else {
            std::cout << "Bad input! Please enter location [Letter][Number] of your desired move, with capital letters fonly:" << std::endl;
            std::getline(std::cin, playerInput);
        }
    }
    return playerInput;
}

// game creation
int main(int argc, char** argv) {
    Game battleship;
    battleship.playGame();
    return 0;
}