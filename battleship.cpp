#include "battleship.hpp"

Battleship::Battleship() {
    this->name = "";
}

bool Battleship::setName(std::string name) {
    if (name == "")
        return false;

    this->name = name;

    return (this->name == name) ? true : false;
}

std::string Battleship::getName() {
    return this->name;
}