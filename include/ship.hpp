#ifndef __SHIP_HPP__
#define __SHIP_HPP__

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
        std::map<const std::pair<int, int>, bool> getPos();
        bool setPos(int x, int y, bool vertical);
        bool checkHit(std::pair<int, int> pos);
        bool alive;

    private:
        // std::vector<const std::pair<int,int>, bool> hp;
        std::map<const std::pair<int, int>, bool> hp;
};

class carrier {
    public:
        carrier();
        // ~carrier();
    private:
        int length;
        bool vertical;
};

class battleship {
    public:
        // using Ship::Ship;
        battleship();
        // ~battleship();
    private:
        int length;
        bool vertical;
};

class patrol {
    public:
        patrol();
        // ~patrol();
    private:
        int length;
        bool vertical;
};

class submarine {
    public:
        submarine();
        // ~submarine();
    private:
        int length;
        bool vertical;
};

class destroyer {
    public:
        destroyer();
        // ~destroyer();
    private:
        int length;
        bool vertical;
};

#endif
