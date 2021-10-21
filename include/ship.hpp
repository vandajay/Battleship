#ifndef __BATTLESHIP_HPP__
#define __BATTLESHIP_HPP__

#include <string>
#include <stdio.h>

class Ship {
    public:
        Ship();
        ~Ship();
        bool setName(std::string name);
        std::string getName();

    private:
        std::string name;
};

#endif