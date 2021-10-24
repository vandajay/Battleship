#include "include/ship.hpp"
#include "include/game.hpp"
#include "include/board.hpp"


Game::Game() {
    Board player = Board();
    Board enemy = Board();
    Board playerHistory = Board();
    Board enemyHistory = Board();

    player.printBoard(true);
}

Game::~Game();

void Game::startGame() {
    std::cout << "|---------------------------- BATTLESHIP ----------------------------|" << std::endl;
}

void Game::setPlayerBoard() {

}

void Game::setEnemyBoard(){

}