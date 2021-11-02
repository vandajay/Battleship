
#include "Ship.hpp"
#include "Values.hpp"

/***********************************************************************
 * Constuctor that creates a ship using length, and name.
 * @param int length length/hp of ship
 * @param std::string name of ship
 **********************************************************************/
Ship::Ship(int length, std::string n) {
    this->shipLength = length;
    name = n;
    this->shipSquares = new char[this->shipLength];
    for (int i = 0; i < this->shipLength; ++i)
        this->shipSquares[i] = isSHIP; // initialize ship char
    this->xCoord = -1; // not placed yet
    this->yCoord = -1;
    this->isSunk = false;
    this->isHorizontal = true;
}

/***********************************************************************
 * Getter function for retrieving ship length.
 * @return int length of ship
 **********************************************************************/
int Ship::getSize() const {
    return this->shipLength;
}

/***********************************************************************
 * Getter function for retrieving ship x coordinate.
 * @return int x coordintate of ship, [A-J] on board
 **********************************************************************/
int Ship::getX() const {
    return this->xCoord;
}

/***********************************************************************
 * Getter function for retrieving ship y coordinate.
 * @return int y coordintate of ship [0-9] on board
 **********************************************************************/
int Ship::getY() const {
    return this->yCoord;
}

/***********************************************************************
 * Getter function for retrieving a ships sunk state.
 * @return bool true if ship is sunk, false if afloat
 **********************************************************************/
bool Ship::isShipSunk() const {
    return this->isSunk;
}

/***********************************************************************
 * Getter function for finding if a ship is horizontal or vertical.
 * @return bool true for horizontal, false for vertical
 **********************************************************************/
bool Ship::isShipHorizontal() const {
    return this->isHorizontal;
}

/***********************************************************************
 * Getter function for retrieving ship name.
 * @return std::string ship name
 **********************************************************************/
std::string Ship::getName() const {
    return this->name;
}

/***********************************************************************
 * Setter function for setting the topmost/leftmost position of a ship.
 * @param int x x coordintate of ship, [A-J] on board
 * @param int y y coordintate of ship [0-9] on board
 * @param bool h true for horizontal, false for vertical
 **********************************************************************/
void Ship::setPosition(int x, int y, bool h) {
    xCoord = x;
    yCoord = y;
    this->isHorizontal = h;
}

/***********************************************************************
 * Setter function for recording hits to ship.
 * @param int targetX x coordinate for target cell, [A-J] on board
 * @param int targetX y coordinate for target cell, [0-9] on board
 * @return bool true on a successful hit, false for a miss
 **********************************************************************/
bool Ship::setHit(int targetX, int targetY) {
    // check for prexisting hit
    if ((this->isHorizontal & (targetX < this->xCoord || targetX >= this->xCoord + this->shipLength
        || targetY != yCoord))
        || (!this->isHorizontal & (targetY < this->yCoord || targetY >= this->yCoord + this->shipLength
            || targetX != this->xCoord))) // miss
        return false; 
    else { // hit
        if (isHorizontal)
            this->shipSquares[targetX - this->xCoord] = isHIT;
        else
            this->shipSquares[targetY - this->yCoord] = isHIT;
    }

    this->isSunk = true;
    // is ship sunk
    for (int i = 0; i < this->shipLength; ++i)
        if (this->shipSquares[i] == isSHIP)
            this->isSunk = false;

    return true;
}