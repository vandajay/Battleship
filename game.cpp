#include "include/ship.hpp"

Ship::Ship() {
    this->name = "";
}

bool Ship::setName(std::string name) {
    if (name == "")
        return false;

    this->name = name;

    return (this->name == name) ? true : false;
}

std::string Ship::getName() {
    return this->name;
}