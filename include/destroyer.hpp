#ifndef __DESTROYER_HPP__
#define __DESTROYER_HPP__

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <array>
#include <map>

// MODEL

class Destroyer {
    public:
        Destroyer();
        std::map<const std::pair<int, int>, bool> getPos();
        bool setPos(const std::pair<int, int> pos);
        bool checkHit(std::pair<int, int> pos);
        bool alive;
        int length;
        bool vertical;

    private:

};

#endif