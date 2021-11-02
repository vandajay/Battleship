#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "Ship.hpp"
#include "Values.hpp"
#include <vector>
#include <iostream>


class Board
{
	private:
		std::vector<Ship> shipVector;
	public:
		Board();
		int getNumHits();
		void printPrivateBoard();
		void printPublicBoard();
		char getCellState(int x, int y);
		bool setHit(int x, int y);
		bool placeShip(int shipNum, int x, int y, bool isHorizontal);
		char board[BOARD_DIM][BOARD_DIM];

		// friend std::ostream& operator<<(std::ostream& output, Board& b); // attempt at stream operator overloading
};

#endif