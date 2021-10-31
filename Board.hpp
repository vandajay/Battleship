#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "Ship.hpp"
#include "Values.hpp"
#include <vector>
#include <stdio.h>
#include <ostream>


class Board
{
	private:
		std::vector<Ship> shipVec;

	public:
		// friend class Game;
		char gameBoard[BOARD_DIM][BOARD_DIM];

		Board();
		~Board();
		int getNumHits();
		void printPrivateBoard();
		void printPublicBoard();
		char getSpaceValue(int x, int y);
		bool recordHit(int x, int y);
		bool placeShip(int shipNum, int x, int y, bool isHorizontal);
};

#endif