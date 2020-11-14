#include <stdio.h>
#include <vector>
class TictactoeUI
{
	private:
		const int SIDE;
		std::vector<std::vector<char> > board;
	public:
	TictactoeUI() : SIDE(3)
	{
		std::vector<char> row(SIDE,' ');
		board = std::vector<std::vector<char> > (SIDE,row);
	}
	void showBoard() 
	{ 
    	printf("\n\n"); 
      	printf("\t\t\t  %c | %c  | %c  \n", board[0][0], 
                             board[0][1], board[0][2]); 
    	printf("\t\t\t--------------\n"); 
    	printf("\t\t\t  %c | %c  | %c  \n", board[1][0], 
                             board[1][1], board[1][2]); 
    	printf("\t\t\t--------------\n"); 
    	printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0], 
                             board[2][1], board[2][2]);  
	}

	void resetBoard()
	{
		for(int i = 0 ; i < board.size() ; i++)
		{
			for(int j = 0 ; j < board[i].size() ; j++)
			{
				board[i][j] = ' ';
			}
		}
	}
	void markPositionXY(int X,int Y,int player)
	{
		if(player == 0)
		{
			board[X][Y] = 'O';
		}
		else
		{
			board[X][Y] = 'X';	
		}
	}
	void unmarkPositionXY(int X,int Y,int player)
	{
		board[X][Y] = ' ';
	}
};