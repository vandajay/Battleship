#include "include/carrier.hpp"
#include <typeinfo>

Carrier::Carrier() {
    alive = true;
    length = 5;
    vertical = true;
}

void Carrier::setPos(const std::pair<int, int> pos) {

    this->setPos(pos);
}