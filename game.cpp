#include "include/ship.hpp"
#include "include/game.hpp"
#include "include/board.hpp"


Game::Game() {
    Board player = Board();
    Board enemy = Board();
}

Game::~Game() {}

void Game::setPlayerBoard() {

}

void Game::setEnemyBoard() {

}

void Game::startGame() {
    std::cout << R"(
|---------------------------- BATTLESHIP ----------------------------|
	    )" << std::endl;


    Board::printBoard(true);
}
