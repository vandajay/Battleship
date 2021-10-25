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

    // Ship* pCarrier;
    // Ship* pBattleship;
    // Ship* pPatrol;
    // Ship* pSubmarine;
    // Ship* pDestroyer;

    // Ship* eCarrier;
    // Ship* eBattleship;
    // Ship* ePatrol;
    // Ship* eSubmarine;
    // Ship* eDestroyer;


    // pCarrier = new Ship('C', 5);
    // pBattleship = new Ship('B', 4);
    // pPatrol = new Ship('P', 3);
    // pSubmarine = new Ship('S', 3);
    // pDestroyer = new Ship('D', 2);

    // eCarrier = new Ship('C', 5);
    // eBattleship = new Ship('B', 4);
    // ePatrol = new Ship('P', 3);
    // eSubmarine = new Ship('S', 3);
    // eDestroyer = new Ship('D', 2);
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

bool Game::setPlayerShip(Ship* ship, bool v, std::pair<int, int> coord) {


    switch (ship->name) {
    case 'C':
        std::cout << "Setting Carrier..." << std::endl;
        break;

    case 'B':
        std::cout << "Setting Battleship..." << std::endl;
        break;

    case 'P':
        std::cout << "Setting Patrol..." << std::endl;
        break;

    case 'S':
        std::cout << "Setting Submarine..." << std::endl;
        break;

    case 'D':
        std::cout << "Setting Destroyer..." << std::endl;
        break;

    default:
        break;
    }

    setVertical(ship, v);
    setShipCoord(ship, coord);

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

        Game::setPlayerShip(this->cShip, Game::getPlayerVertical(), Game::getPlayerCoord());
        Game::setPlayerShip(this->bShip, Game::getPlayerVertical(),Game::getPlayerCoord());
        Game::setPlayerShip(this->pShip, Game::getPlayerVertical(), Game::getPlayerCoord());
        Game::setPlayerShip(this->sShip, Game::getPlayerVertical(), Game::getPlayerCoord());
        Game::setPlayerShip(this->dShip, Game::getPlayerVertical(), Game::getPlayerCoord());
    }
}

// while (s != "y" && s != "n" && s != "Y" && s != "N") {
//     std::cout << "please enter y/n: ";
//     getline(cin, s);
// }