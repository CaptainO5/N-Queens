#include"NQueen.h"

nQueen :: nQueen() {
	cout << "Enter n: ";
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			board[i][j] = '_';
}

bool nQueen :: isProtected(struct position q) {
	int i, j;
	for(i = 0; i < q.row; i ++)
		if(board[i][q.col] == 'Q')
			return true;
			
	/* 
	for(j = 0; j < q.col; j ++)
		if(board[q.row][j] == 'Q')
			return true;
	*/
	
	for(i = q.row, j = q.col; i >= 0 && j >= 0; i --, j --)
		if(board[i][j] == 'Q')
			return true;		

	for(i = q.row, j = q.col; i >= 0 && j < n; i --, j ++)
		if(board[i][j] == 'Q')
			return true;
	return false;	
}

int nQueen :: printBoard() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << board[i][j] << "  ";
		cout << endl;
	}
	return 0;
}

int nQueen :: solveNQueen() {
	if(n < 4) {
		cout << "NO SOLUTION\n";
		return 1;
	}
	stack s;
	struct position q = {0, 0};
		
	while(q.row < n) {
		for(; q.col < n; q.col ++) {
			if(!isProtected(q)) {
				board[q.row][q.col] = 'Q';
				s.push(q);
				q.row ++;
				q.col = 0;
				break;
			}
		}	
		
		while(q.col >= n) {
			s.pop(&q);
			board[q.row][q.col] = '_';
			q.col ++;
		}
	}
	printBoard();
	return 0;
}
