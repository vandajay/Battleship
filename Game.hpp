#include "Board.hpp"

#ifndef __GAME_HPP__
#define __GAME_HPP__

enum state {PLAYER_WIN, ENEMY_WIN, UNFINISHED};

class Game
{
	private: 
		Board* playerBoard;
		Board* enemyBoard;
	public:
		// Board playerBoard;
		// Board enemyBoard;
		bool playGame();
		void startGame();
		void initializeBoard(Board &b);
		void initializeBoardAuto(Board &b);
		state gameCondition();
		void printGameState();
		void getNextMove();
		void getNextMoveAuto();
		std::string getSquare();
		int getInt(int min, int max);

		friend std::ostream& operator<<(std::ostream& output, Board& b);

};

#endif 