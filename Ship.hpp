#include <string>

#ifndef __SHIP_HPP__
#define __SHIP_HPP__

class Ship
{
	private: 
		char* shipSquares;
		int shipSize;
		int xCoord, yCoord; //upper left corner of ship
		bool isSunk;
		bool isHorizontal;
		std::string name;


	public:	
		Ship(int size,  std::string n);//default constructor
		~Ship(); //destructor
		int getSize() const;
		int getX() const;
		int getY() const;
		bool isShipSunk() const;
		bool isShipHorizontal() const;
		std::string getName() const;
		void setPosition(int x, int y, bool h);
		bool recordHit(int hitLocX, int hitLocY);
};

#endif