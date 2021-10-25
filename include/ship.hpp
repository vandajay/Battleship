#ifndef __SHIP_HPP__
#define __SHIP_HPP__

#include "game.hpp"
// #include "include/ship.hpp"
// #include "include/board.hpp"

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <array>
#include <map>

// MODEL

class Ship {
    public:
        Ship(char c, int l);
        ~Ship();
        std::map<std::pair<int, int>, bool> getPos();
        bool setShipCoord(Ship* s, std::pair<int,int> coord);
        bool checkHit(std::pair<int, int> pos);
        int getLength() { return length; }
        void setVertical(Ship* s, bool v) { vertical = v; }
        bool getVertical() { return vertical; }

        char name;
        bool alive;
        int length;
        bool vertical;
        std::map<std::pair<int, int>, bool> hp;

    private:
        // std::vector<std::pair<int,int>, bool> hp;
};

// class carrier : public Ship {
//     public:
//         carrier();
//         // ~carrier();
//         int getLength() { return length; }
//         void setVertical(bool v) { vertical = v; }
//         bool getVertical() { return vertical; }

//     private:
//         int length;
//         bool vertical;
// };

// class battleship : public Ship {
//     public:
//         battleship();
//         // ~battleship();
//         int getLength() { return length; }
//         void setVertical(bool v) { vertical = v; }
//         bool getVertical() { return vertical; }

//     private:
//         int length;
//         bool vertical;
// };

// class patrol : public Ship {
//     public:
//         patrol();
//         // ~patrol();
//         int getLength() {return length;}
//         void setVertical(bool v) {vertical = v;}
//         bool getVertical() { return vertical;}


//     private:
//         int length;
//         bool vertical;
// };

// class submarine : public Ship {
//     public:
//         submarine();
//         // ~submarine();
//         int getLength() { return length; }
//         void setVertical(bool v) { vertical = v; }
//         bool getVertical() { return vertical; }

//     private:
//         int length;
//         bool vertical;
// };

// class destroyer : public Ship {
//     public:
//         destroyer();
//         // ~destroyer();
//         int getLength() { return length; }
//         void setVertical(bool v) { vertical = v; }
//         bool getVertical() { return vertical; }

//     private:
//         int length;
//         bool vertical;
// };

#endif
