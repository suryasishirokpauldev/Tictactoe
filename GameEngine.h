#include <vector>
#include <set>
#include "tictactoeui.h"

enum GAME_STATUS
{
	PLAYER1_WON,
	PLAYER2_WON,
	NO_MOVES_LEFT,
	GAME_CONTINUES
};

class GameEngine
{
	private:
		std::vector<int> rowSum;
		std::vector<int> colSum;
		int diagonalSum;
		int crossDiagonalSum;
		std::set<std::pair<int,int> > moveAlreadyMade;
		int sizeOfSquare;
		TictactoeUI tictactoeui;
		int currentPlayer;
		void makeMove(int x,int y,int currentPlayer)
		{
			if(currentPlayer == 1)
			{
				rowSum[x]++;
				colSum[y]++;
				if(x == y)
				{
					diagonalSum++;
				}
				if(x+y == (sizeOfSquare-1))
				{
				crossDiagonalSum++;
				}
			}
			else
			{
				rowSum[x]--;
				colSum[y]--;
				if(x == y)
				{
					diagonalSum--;
				}
				if(x+y == (sizeOfSquare-1))
				{
					crossDiagonalSum--;
				}

			}
		}
	public:
		GameEngine(int n) : currentPlayer(0),rowSum(std::vector<int>(n,0)),colSum(std::vector<int>(n,0)),diagonalSum(0),crossDiagonalSum(0),sizeOfSquare(n)
		{
		}

		bool isCellEmpty(int x,int y)
		{
			return (moveAlreadyMade.find(std::make_pair(x,y)) == moveAlreadyMade.end());
		}
		int abs(int value)
		{
			if(value < 0)
				return (-1*value);
			return value;
		}
		
		
		GAME_STATUS getGameStatus(int x,int y,int currentPlayer)
		{
			if(moveAlreadyMade.size() == (sizeOfSquare*sizeOfSquare))
				return NO_MOVES_LEFT;
			bool check = (crossDiagonalSum == abs(sizeOfSquare) || diagonalSum == abs(sizeOfSquare) || rowSum[x] == abs(sizeOfSquare) || colSum[y] == abs(sizeOfSquare));
			if(check && currentPlayer == 1)
			{
				return PLAYER2_WON;
			}
			if(check && currentPlayer == 0)
			{
				return PLAYER1_WON;
			}
			return GAME_CONTINUES;
		}


		void playGame()
		{
			GAME_STATUS gameStatus = GAME_CONTINUES;
			while(1)
			{
				tictactoeui.showBoard();
				std::cout<<"Player "<<currentPlayer+1<<"to move"<<std::endl;
				std::cout<<"Enter next move"<<std::endl;
				int x,y;
				std::cin>>x>>y;

				if(isCellEmpty(x,y))
				{
					tictactoeui.markPositionXY(x,y,currentPlayer);
					currentPlayer = 1 - currentPlayer;
					moveAlreadyMade.insert(std::make_pair(x,y));
					makeMove(x,y,currentPlayer);	
					if(getGameStatus(x,y,currentPlayer) == NO_MOVES_LEFT || getGameStatus(x,y,currentPlayer) == PLAYER1_WON || getGameStatus(x,y,currentPlayer) == PLAYER2_WON)
					{
						gameStatus = getGameStatus(x,y,currentPlayer); 
						break;
					}		
				}
				else
				{
					std::cout<<"Invalid move:Cell already occupied"<<std::endl;
				}				
			}
			tictactoeui.showBoard();
			if(gameStatus == PLAYER1_WON)
			{
				std::cout<<"Player 1 has won"<<std::endl;
			}
			else
			if(gameStatus == PLAYER2_WON)
			{
				std::cout<<"Player 2 has won"<<std::endl;	
			}
			else
			if(gameStatus == NO_MOVES_LEFT)
			{
				std::cout<<"Game Ended.Nobody won."<<std::endl;	
			}
			
		}

};