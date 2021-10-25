#include "include/carrier.hpp"
#include "include/battleship.hpp"
#include "include/patrol.hpp"
#include "include/submarine.hpp"
#include "include/destroyer.hpp"

#include "include/game.hpp"
#include "include/board.hpp"

#include <utility>
#include <iostream>

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
            // sleep(1);
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

bool Game::setPlayerShip(int ship, bool vertical, std::pair<int, int> coord) {


    switch (ship) {
        case 0:
            std::cout << "Setting Carrier..." << std::endl;
            break;

        case 1:
            std::cout << "Setting Battleship..." << std::endl;
            break;

        case 2:
            std::cout << "Setting Patrol..." << std::endl;

            break;

        case 3:
            std::cout << "Setting Submarine..." << std::endl;
            break;

        case 4:
            std::cout << "Setting Destroyer..." << std::endl;
            break;

        default:
            break;
    }

    return true;
}

void Game::printBoard(Board &b) {
    int width = 10;
    std::cout << " 0123456789" << std::endl;

    for (int y = 0; y < width; ++y) {
        std::cout << y;
        for (int x = 0; x < width; ++x) {
            std::cout << b.board[x][y];
            if (x == width - 1)
                std::cout << std::endl;
        }
    }
}

void Game::startGame() {
    int count = 5;
    std::pair<int, int> coord;
    bool vertical;

    Board* player = new Board();
    Board* enemy = new Board();

    Carrier* eC;
    Battleship* eB;
    Patrol* eP;
    Submarine* eS;
    Destroyer* eD;

    Carrier* pC;
    Battleship* pB;
    Patrol* pP;
    Submarine* pS;
    Destroyer* pD;

    Game::printBoard(*(player)); // TODO

    for (int i = 0; i < count; ++i) {
        coord = getPlayerCoord();
        vertical = getPlayerVertical();
    }

    getPlayerCoord();

    std::cout << "|---------------------------- BATTLESHIP ----------------------------|" << std::endl;
}