#ifndef __CARRIER_HPP__
#define __CARRIER_HPP__

#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <array>
#include <map>

// MODEL

class Carrier {
    public:
        Carrier();

        std::map<const std::pair<int, int>, bool> getPos();
        // bool setPos(int x, int y, bool vertical);
        void setPos(const std::pair<int, int> pos);

        bool checkHit(std::pair<int, int> pos);
        bool alive;
        int length;
        bool vertical;

    private:

};

#endif