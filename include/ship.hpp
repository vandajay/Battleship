#ifndef __SHIP_HPP__
#define __SHIP_HPP__

// #include "include/game.hpp"
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
        Ship();
        ~Ship();
        std::map<std::pair<int, int>, bool> getPos();
        bool setShipCoord(std::pair<int, int>, bool vertical);
        bool checkHit(std::pair<int, int> pos);

        bool alive;
        std::map<std::pair<int, int>, bool> hp;

    private:
        // std::vector<std::pair<int,int>, bool> hp;
};

class carrier : public Ship {
    public:
        carrier();
        // ~carrier();
        int getLength() { return length; }
        void setVertical(bool v) { vertical = v; }
        bool getVertical(bool v) { return vertical; }

    private:
        int length;
        bool vertical;
};

class battleship : Ship {
    public:
        battleship();
        // ~battleship();
        int getLength() { return length; }
        void setVertical(bool v) { vertical = v; }
        bool getertical(bool v) { return vertical; }

    private:
        int length;
        bool vertical;
};

class patrol : Ship {
    public:
        patrol();
        // ~patrol();
        int getLength() {return length;}
        void setVertical(bool v) {vertical = v;}
        bool getertical(bool v) { return vertical;}


    private:
        int length;
        bool vertical;
};

class submarine : Ship {
    public:
        submarine();
        // ~submarine();
        int getLength() { return length; }
        void setVertical(bool v) { vertical = v; }
        bool getertical(bool v) { return vertical; }

    private:
        int length;
        bool vertical;
};

class destroyer : Ship {
    public:
        destroyer();
        // ~destroyer();
        int getLength() { return length; }
        void setVertical(bool v) { vertical = v; }
        bool getertical(bool v) { return vertical; }

    private:
        int length;
        bool vertical;
};

#endif
