#include <string> 

#ifndef __SHIP_HPP__
#define __SHIP_HPP__

class Ship
{
	private: 
		char* shipSquares;
		int shipLength;
		int xCoord, yCoord; //upper left corner of ship
		bool isSunk;
		bool isHorizontal;
		std::string name;


	public:	
		Ship(int length,  std::string n);
		int getSize() const;
		int getX() const;
		int getY() const;
		bool isShipSunk() const;
		bool isShipHorizontal() const;
		std::string getName() const;
		void setPosition(int x, int y, bool h);
		bool setHit(int targetX, int targetY);
};

#endif