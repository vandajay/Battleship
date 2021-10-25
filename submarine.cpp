#include "include/submarine.hpp"
#include <typeinfo>

Submarine::Submarine() {
    alive = true;
    length = 5;
    vertical = true;
}

bool Submarine::setPos(const std::pair<int, int> pos) {

}