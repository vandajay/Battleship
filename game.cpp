#include "Game.hpp"
#include <iostream>
#include <random>

void Game::startGame() {
    playerBoard = new Board();
    enemyBoard = new Board();
    initializeBoard();
    initializeBoardAuto();
    std::cout << std::endl << "** GAME START **" << std::endl;
}

bool Game::playGame() {
    startGame();
    while(gameCondition() == UNFINISHED) {
        printGameState();
        getNextMove();
        getNextMoveAuto();
    }

    if (gameCondition() == PLAYER_WIN)
        std::cout << "Player wins!" << std::endl;
    else
        std::cout << "Enemy wins!" << std::endl;
    
    return true;
}

void Game::initializeBoard() {
    int xEntry, yEntry, attemptCount, horizEntry;
    std::string entryTemp,horizTemp;
    for (int i = 0; i < NUM_SHIPS; i++) 	{
        attemptCount = 0;
        do // check for valid placement of each ship
        {
            std::cout << std::endl;
            playerBoard->printPublicBoard();
            std::cout << std::endl;
            if (attemptCount > 0)
                std::cout << "INVALID ENTRY for that ship! Please try again." << std::endl;

            std::cout << "Placing " << SHIP_NAMES[i] << ", Length " << SHIP_LENGTHS[i] << "..." << std::endl;
            std::cout << "Enter coordinate [A-J][0-9]:" << std::endl;
            entryTemp = getSquare();
            xEntry = static_cast<int>(entryTemp[0]);
            yEntry = static_cast<int>(entryTemp[1]);

            std::cout << "Please enter 0 if the ship is oriented vertically, 1 if it is oriented horizontally:" << std::endl;
            
            std::getline(std::cin, horizTemp);
            horizEntry = std::stoi(horizTemp);

            attemptCount++;
        } while (!playerBoard->placeShip(i, xEntry - ASCII_CHAR_MIN,
            yEntry - ASCII_INT_MIN, horizEntry));
    }
}

void Game::initializeBoardAuto() {
    std::random_device device;
    std::mt19937 gen32(device());
    std::uniform_int_distribution<int> distribution9(0, 9);
    std::uniform_int_distribution<int> distribution1(0, 1);
    int xEntry, yEntry, horizEntry;

    for (int i = 0; i < NUM_SHIPS; i++) {
        do // randomize position placements and place ships if possible
        {
            xEntry = distribution9(gen32) % 10;
            yEntry = distribution9(gen32) % 10;
            horizEntry = distribution1(gen32) % 2;
        } while (!enemyBoard->placeShip(i, xEntry, yEntry, horizEntry));

    }
}

state Game::gameCondition() {
    if (playerBoard->getNumHits() == TOTAL_SHIP_SPACES)
        return ENEMY_WIN;
    else if (enemyBoard->getNumHits() == TOTAL_SHIP_SPACES)
        return PLAYER_WIN;
    else
        return UNFINISHED;
}

void Game::printGameState() {
    std::cout << std::endl << "ENEMY BOARD:" << std::endl;
    enemyBoard->printPublicBoard(); // Used for debugging
    // enemyBoard->printPrivateBoard();

    std::cout << std::endl << "PLAYER BOARD:" << std::endl;
    playerBoard->printPublicBoard();
    std::cout << std::endl;
}

void Game::getNextMove() {
    int cnt = 0;
    int xEntry, yEntry;
    bool goodMove = false;
    std::string entryTemp;

    while (!goodMove) {
        if (cnt > 0)
            std::cout << "Move already exists..." << std::endl;

        std::cout << "Enter move [A-J][0-9]:" << std::endl;
        entryTemp = getSquare();
        xEntry = static_cast<int>(entryTemp[0]);
        yEntry = static_cast<int>(entryTemp[1]);

        if (enemyBoard->getSpaceValue(xEntry - ASCII_CHAR_MIN,
            yEntry - ASCII_INT_MIN) != isHIT
            && enemyBoard->getSpaceValue(xEntry - ASCII_CHAR_MIN,
                yEntry - ASCII_INT_MIN) != isMISS) {
            enemyBoard->recordHit(xEntry - ASCII_CHAR_MIN, yEntry - ASCII_INT_MIN);
            goodMove = true;
        }
        cnt++;
    }
}

void Game::getNextMoveAuto() {
    std::random_device device;
    std::mt19937 gen32(device());
    std::uniform_int_distribution<int> distribution9(0, 9);
    bool goodMove = false;
    int xEntry, yEntry;

    while (!goodMove) 	{
        // randomly choose next move
        xEntry = distribution9(gen32) % 10;
        yEntry = distribution9(gen32) % 10;

        if (playerBoard->getSpaceValue(xEntry, yEntry) != isHIT && playerBoard->getSpaceValue(xEntry, yEntry) != isMISS) {
            playerBoard->recordHit(xEntry, yEntry);
            goodMove = true;
        }
    }
}

std::string Game::getSquare() {
    std::string retString;
    std::getline(std::cin, retString);
    bool isGoodInput = false;

    while (!isGoodInput) {
        /**
         * check for two character entries of letter/number
         * A=65, J=74, 48=0, 9=57
         */
        if (retString.length() == 2 && (retString[0] >= 65 && retString[0] <= 74) && (retString[1] >= 48 && retString[1] <= 57)) {
            isGoodInput = true;
        } else {
            std::cout << "Bad input! Please enter location [Letter][Number] of your desired move, with capital letters fonly:" << std::endl;
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