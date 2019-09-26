//UVa 10363 - Tic Tac Toe
#include<bits/stdc++.h>
using namespace std;

void checkWin(char board[4][4], char s) {
	bool flag  = true;
	for(int i = 0; i < 3; i++) {
		if(board[0][i] == s && board[1][i] == s && board[2][i] == s || 
		   board[i][0] == s && board[i][1] == s && board[i][2] == s ) {
			   flag = false;
		   }
	}
	if(board[0][0] == s && board[1][1] == s && board[2][2] == s) flag = false;
	if(board[0][2] == s && board[1][1] == s && board[2][0] == s) flag = false;

	if(!flag) {
		printf("no \n");
	} else {
		printf("yes \n");
	}
}

int main() {
	int n, countX, countO;
	char board[4][4];
	cin >> n;
	while(n--) {
		countX = 0;
		countO = 0;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				cin >> board[i][j];
				if(board[i][j] == 'X') {
					countX++;
				} else 
				if(board[i][j] == 'O') {
					countO++;
				}
			}
		}
		if(countO > countX) {
			printf("no \n");
		} else 
		if(countO == countX) {
			checkWin(board, 'X');
		} else {
			checkWin(board, 'O');
		}
	}
	return 0;
}
