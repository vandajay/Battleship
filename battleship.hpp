#ifndef __BATTLESHIP_HPP__
#define __BATTLESHIP_HPP__

#include <string>
#include <stdio.h>

class Battleship {
    public:
        Battleship();
        ~Battleship();
        bool setName(std::string name);
        std::string getName();

    private:
        std::string name;
};

#endif