#include "include/destroyer.hpp"
#include <typeinfo>

Destroyer::Destroyer() {
    alive = true;
    length = 5;
    vertical = true;
}

bool Destroyer::setPos(const std::pair<int, int> pos) {

}