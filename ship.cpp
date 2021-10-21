#include "include/ship.hpp"

Ship::Ship() {
    status = ALIVE;
}

Ship::~Ship() {

}

Ship::type::carrier::carrier() {
    length = 5;
    vertical = true;
}

Ship::type::battleship::battleship() {
    length = 4;
    vertical = true;
}

Ship::type::patrol::patrol() {
    length = 3;
    vertical = true;
}

Ship::type::submarine::submarine() {
    length = 3;
    vertical = true;
}

Ship::type::destroyer::destroyer() {
    length = 2;
    vertical = true;
}

bool Ship::checkHit(const std::pair<int,int> pos) {
    // see if position exists on ship map and set damage to pos at true
    if (hp.end() == hp.find(pos)) {
        hp[pos] = true;
        return true;
    }
    return false;
}

bool Ship::setPos(int x, int y, bool vertical) {
    std::pair<int,int> pos = std::make_pair(x,y);
    this->hp[pos] = false;
    return (this->hp[pos] = false) ? true : false;
}

std::map<const std::pair<int,int>, bool> Ship::getPos() {
    return this->hp;
}
