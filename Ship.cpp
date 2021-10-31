
#include "Ship.hpp"
#include "Values.hpp"
#include <iostream>

Ship::Ship(int size, std::string n) {
    shipSize = size;
    name = n;
    shipSquares = new char[shipSize];
    for (int i = 0; i < shipSize; i++)
        shipSquares[i] = isSAFESHIP; //initialize all ship squares to '_', no hit
    xCoord = -1; //indicates that the ship has not been placed yet
    yCoord = -1; //indicates that the ship has not been placed yet
    isSunk = false; //since ship is new, it is not yet sunk
    isHorizontal = true;
}

Ship::~Ship() {
    // if (shipSize > 0)
    //     delete[] shipSquares;
}

int Ship::getSize() const {
    return shipSize;
}

int Ship::getX() const {
    return xCoord;
}

int Ship::getY() const {
    return yCoord;
}

bool Ship::isShipSunk() const {
    return isSunk;
}

bool Ship::isShipHorizontal() const {
    return isHorizontal;
}

std::string Ship::getName() const {
    return name;
}

void Ship::setPosition(int x, int y, bool h) {
    xCoord = x;
    yCoord = y;
    isHorizontal = h;
}

bool Ship::recordHit(int hitLocX, int hitLocY) {
    //check to make sure that the hit is located on the ship, return if not
    if ((isHorizontal & (hitLocX < xCoord || hitLocX >= xCoord + shipSize
        || hitLocY != yCoord))
        || (!isHorizontal & (hitLocY < yCoord || hitLocY >= yCoord + shipSize
            || hitLocX != xCoord)))
        return false; //return false because it was not a hit
    else // if there is a hit, record it on the ship
    {
        if (isHorizontal)
            shipSquares[hitLocX - xCoord] = isHIT;
        else
            shipSquares[hitLocY - yCoord] = isHIT;
    }

    //determine whether the ship has been sunk
    isSunk = true;
    for (int i = 0; i < shipSize; i++)
        if (shipSquares[i] == isSAFESHIP)
            isSunk = false;

    return true;
}