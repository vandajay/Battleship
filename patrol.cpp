#include "include/patrol.hpp"
#include <typeinfo>

Patrol::Patrol() {
    alive = true;
    length = 5;
    vertical = true;
}

bool Patrol::setPos(const std::pair<int, int> pos) {

}