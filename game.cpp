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
    int v;
    int isVertical;

    do {
        std::cout << std::endl;
        std::cout << "Set vertical (y/n): ";
        std::cin >> v;
        if (v == 1) {
            isVertical = true;
        }
        else if (v == 0) {
            isVertical = false;
        }
        else {
            std::cout << "Retry: Enter y/n" << std::endl;
        }
    } while (v != 1 && v != 0);

    return isVertical;
}

bool Game::setPlayerShip(int ship) {
    std::pair<int, int> coord;
    bool vertical;

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
    }

    coord = getPlayerCoord();
    vertical = getPlayerVertical();






    return true;
}

void Game::printBoard(Board& b) {
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

bool place(Board &b, int ship, std::pair<int,int> coord, bool isVertical) {
    int len;
    char ch;
    switch (ship) {
    case 0:
        len = 5;
        ch = 'C';
        break;
    case 1:
        len = 4;
        ch = 'B';
        break;
    case 2:
        len = 3;
        ch = 'P';
        break;
    case 3:
        len = 3;
        ch = 'S';
        break;
    case 4:
        len = 2;
        ch = 'D';
        break;
    }
    for (int i = 0; i < len; i++) {
        if (isVertical)
            b.board[coord.first][coord.second + i] = ch;
        else
            b.board[coord.first + i][coord.second] = ch;
    }
}

bool Game::checkCoord(Board& b, int ship, bool isVertical, std::pair<int, int> coord) {
    int len;
    switch (ship) {
        case 0:
            len = 5;
            break;
        case 1:
            len = 4;
            break;
        case 2:
            len = 3;
            break;
        case 3:
            len = 3;
            break;
        case 4:
            len = 2;
            break;
    }

    auto search = b.positions.find(coord);

    // initial position already exists
    if (search != b.positions.end()) {
        std::cout << "Invalid Position" << std::endl;
        return false;
    }
    // coordinate out of bounds
    else if (coord.first >= 10 || coord.second >= 10 || coord.first < 0 || coord.second < 0) { 
        std::cout << "Invalid Position" << std::endl;
        return false;
    }
    
    for (int i = 0; i < len; i++) {
        if ((isVertical && b.board[coord.first][coord.second + i] != '~') || (!isVertical && b.board[coord.first + i][coord.second] != '~')) {
            std::cout << "Invalid Position" << std::endl;
            return false;
        }
        if ((!isVertical && (coord.first + i) >= 10) ||
            (isVertical && (coord.second + i) >= 10)) {
                std::cout << "Invalid Position" << std::endl;
                return false;
                }
    }    
    b.positions[coord];
}

void Game::startGame() {
    int count = 5;
    std::pair<int, int> coord;
    bool vertical;

    Board* player = new Board();
    Board* enemy = new Board();

    Carrier* pC = new Carrier();
    Battleship* pB = new Battleship();
    Patrol* pP = new Patrol();
    Submarine* pS = new Submarine();
    Destroyer* pD = new Destroyer();

    Carrier* eC = new Carrier();
    Battleship* eB = new Battleship();
    Patrol* eP = new Patrol();
    Submarine* eS = new Submarine();
    Destroyer* eD = new Destroyer();

    Game::printBoard(*(player)); // TODO

    for (int i = 0; i < count; ++i) {
        switch (i) {
        case 0:
            std::cout << "Setting Carrier..." << std::endl;
            coord = getPlayerCoord();
            vertical = getPlayerVertical();
            pC->vertical = vertical;
            checkCoord(*(player), i, vertical, coord);
            place(*(player), i, coord, vertical);
            break;

        case 1:
            std::cout << "Setting Battleship..." << std::endl;
            coord = getPlayerCoord();
            vertical = getPlayerVertical();
            pB->vertical = vertical;
            checkCoord(*(player), i, pB->vertical, coord);
            place(*(player), i, coord, vertical);
            break;

        case 2:
            std::cout << "Setting Patrol..." << std::endl;
            coord = getPlayerCoord();
            vertical = getPlayerVertical();
            pP->vertical = vertical;
            checkCoord(*(player), i, pP->vertical, coord);
            place(*(player), i, coord, vertical);
            break;

        case 3:
            std::cout << "Setting Submarine..." << std::endl;
            coord = getPlayerCoord();
            vertical = getPlayerVertical();
            pS->vertical = vertical;
            checkCoord(*(player), i, pS->vertical, coord);
            place(*(player), i, coord, vertical);
            break;

        case 4:
            std::cout << "Setting Destroyer..." << std::endl;
            coord = getPlayerCoord();
            vertical = getPlayerVertical();
            pD->vertical = vertical;
            checkCoord(*(player), i, pD->vertical, coord);
            place(*(player), i, coord, vertical);
            break;
        }
        printBoard(*(player));
    }



    std::cout << "|---------------------------- BATTLESHIP ----------------------------|" << std::endl;
}