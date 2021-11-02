#include "Board.hpp"
#include <string>

#ifndef __GAME_HPP__
#define __GAME_HPP__

enum state {PLAYER_WIN, ENEMY_WIN, PENDING};

class Game
{
	private: 
		Board* playerBoard;
		Board* enemyBoard;
	public:
		void playGame();
		void startGame();
		void initializeBoardPlayer();
		void initializeBoardBot();
		state getWinner();
		void printGameState();
		void nextMovePlayer();
		void nextMoveBot();
		std::string getSquare();
		int getInt(int min, int max);

		// friend std::ostream& operator<<(std::ostream& output, Board& b);

};

#endif 