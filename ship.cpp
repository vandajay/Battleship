// #include "include/game.hpp"
#include "include/ship.hpp"
// #include "include/board.hpp"

#include <typeinfo>



Ship::Ship() {
    alive = true;
}

Ship::~Ship() {
}

carrier::carrier() {
    length = 5;
    vertical = true;
}

battleship::battleship() {
    length = 4;
    vertical = true;
}

patrol::patrol() {
    length = 3;
    vertical = true;
}

submarine::submarine() {
    length = 3;
    vertical = true;
}

destroyer::destroyer() {
    length = 2;
    vertical = true;
}

bool Ship::checkHit(std::pair<int, int> pos) {
    // see if position exists on ship map and set damage to pos at true
    if (hp.end() == hp.find(pos)) {
        hp[pos] = true;
        return true;
    }
    return false;
}

bool Ship::setShipCoord(std::pair<int,int> coord, bool vertical) {
    // int x = std::get<0>(coord);
    // int y = std::get<1>(coord);
    // std::pair<int, int> pos = std::make_pair(x, y);
    this->hp[coord] = false;
    return (this->hp[coord] = false) ? true : false;
}

std::map<std::pair<int, int>, bool> Ship::getPos() {
    return this->hp;
}
