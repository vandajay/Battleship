#ifndef __GAME_HPP__
#define __GAME_HPP__

#include "ship.hpp"
#include "board.hpp"

// CONTROLLER

/**
 * @brief
 * Carrier      (C)        = 5 Hits
 * Battleship   (B)        = 4 Hits
 * Patrol       (P)        = 3 Hits
 * Submarine    (S)        = 3 Hits
 * Destroyer    (D)        = 2 Hits
 *
 * EMPTY        (?)
 * HIT          (!)
 * MISS         (~)
 */

class Game {
    public:
        Game();
        ~Game();
        int hits;
        int misses;

        void setPlayerBoard();
        void setEnemyBoard();
        void startGame();

    private:
};

#endif