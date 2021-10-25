#ifndef __BATTLESHIP_HPP__
#define __BATTLESHIP_HPP__

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <array>
#include <map>

// MODEL

class Battleship {
    public:
        Battleship();
        std::map<std::pair<int, int>, bool> hp;
        bool setPos(int x, int y, bool vertical);
        bool checkHit(std::pair<int, int> pos);
        bool alive;
        int length;
        bool vertical;

    private:

};

#endif