#include "include/game.hpp"
#include "include/ship.hpp"
#include "include/board.hpp"

#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>



Game::Game() {
    Board player = Board();
    Board enemy = Board();
    playerWins = false;
    enemyWins = false;
    playerSunk = 0;
    enemySunk = 0;
}

Game::~Game() {}

std::pair<int, int> Game::getPlayerCoord() {
    std::string y;
    std::string x;
    int row;
    int col;

    do {
        std::cout << std::endl;
        std::cout << "Enter Row for (0-9): ";
        std::cin >> y;
        row = std::atoi(y.c_str());

        std::cout << "\n" << std::endl;
        std::cout << "Enter Col (0-9): ";
        std::cin >> x;
        col = std::atoi(x.c_str());

        if (row < 0 || row > 9 || col < 0 || col > 9) {
            std::cout << std::endl;
            std::cout << "Retry: Coordinates out of bounds." << std::endl;
            sleep(1);
        }
    } while (row < 0 || row > 9 || col < 0 || col > 9);

    std::pair<int, int> coord = std::make_pair(col, row);

    return coord;
}

bool Game::getPlayerVertical() {
    std::string v;
    int isVertical;

    do {
        std::cout << std::endl;
        std::cout << "Set vertical (y/n): ";
        std::cin >> v;
        if (v == "y") {
            isVertical = true;
        }
        else if (v == "n") {
            isVertical = false;
        }
        else {
            std::cout << "Retry: Enter y/n" << std::endl;
        }
    } while (v != "y" || v != "n");

    return isVertical;
}

void Game::setEnemyBoard() {

}

bool Game::setPlayerShip(char ch, bool vertical, std::pair<int, int> coord) {


    switch (ch) {
    case 'C':
        std::cout << "Setting Carrier..." << std::endl;
        this->cShip->setVertical(vertical);
        this->cShip->setShipCoord(coord, vertical);
        break;

    case 'B':
        std::cout << "Setting Battleship..." << std::endl;
        this->bShip->setVertical(vertical);
        break;

    case 'P':
        std::cout << "Setting Patrol..." << std::endl;
        this->pShip->setVertical(vertical);

        break;

    case 'S':
        std::cout << "Setting Submarine..." << std::endl;
        this->sShip->setVertical(vertical);
        break;

    case 'D':
        std::cout << "Setting Destroyer..." << std::endl;
        this->dShip->setVertical(vertical);
        break;

    default:
        break;
    }

    return true;
}

void Game::startGame() {
    std::cout << R"(
|---------------------------- BATTLESHIP ----------------------------|
	    )" << std::endl;

    while (!Game::playerWins || !Game::enemyWins) {
        std::cout << "ENEMY" << std::endl;
        Board::printBoard(false);
        std::cout << std::endl;
        std::cout << "PLAYER" << std::endl;
        Board::printBoard(true);

        Game::setPlayerShip(
            'C',
            Game::getPlayerVertical(),
            Game::getPlayerCoord()
        );
        Game::setPlayerShip(
            'B',
            Game::getPlayerVertical(),
            Game::getPlayerCoord()
        );
        Game::setPlayerShip(
            'P',
            Game::getPlayerVertical(),
            Game::getPlayerCoord()
        );
        Game::setPlayerShip(
            'S',
            Game::getPlayerVertical(),
            Game::getPlayerCoord()
        );
        Game::setPlayerShip(
            'D',
            Game::getPlayerVertical(),
            Game::getPlayerCoord()
        );
    }
}

// while (s != "y" && s != "n" && s != "Y" && s != "N") {
//     std::cout << "please enter y/n: ";
//     getline(cin, s);
// }