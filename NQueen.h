#include"Stack.h"

class nQueen {
	private: 
		char board[20][20];
		int n;
		bool isProtected(struct position);
		int printBoard();
	public:
		int solveNQueen();
		nQueen();
};
