#ifndef __SUB_HPP__
#define __SUB_HPP__

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <array>
#include <map>

// MODEL

class Submarine {
    public:
        Submarine();
        std::map<const std::pair<int, int>, bool> getPos();
        bool setPos(int x, int y, bool vertical);
        bool checkHit(std::pair<int, int> pos);
        bool alive;
        int length;
        bool vertical;

    private:

};

#endif