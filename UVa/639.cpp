// UVa 639 - Don’t Get Rooked
#include<bits/stdc++.h>
using namespace std;

char filled[4][5];
int n;

bool check(int i, int j) {
	int row, col;
	if(filled[i][j] != '.') return false;
	for(row = i + 1; row  < n; row++) {
		if(filled[row][j] == 'X') break;
		else if(filled[row][j] == 'c') return false;
	}
	for(row = i - 1; row > -1; row--) {
		if(filled[row][j] == 'X') break;
		else if(filled[row][j] == 'c') return false;
	}
	for(col = j + 1; col  < n; col++) {
		if(filled[i][col] == 'X') break;
		else if(filled[i][col] == 'c') return false;
	}
	for(col = j - 1; col > -1; col--) {
		if(filled[i][col] == 'X') break;
		else if(filled[i][col] == 'c') return false;
	}
	return true;
}

int query() {
	int cnt = 0;
	for(int i = 0; i < n; i++){ // rows
		for(int j = 0; j < n; j++){ // coloums
			if(check(i, j)){
				filled[i][j] = 'c';
				cnt = max(cnt, 1 + query());
				filled[i][j] = '.';
			}			
		}
	}
	return cnt;
}
         
int main() {
	char arr[5];
	while(scanf("%d", &n) && n) {
		cin.ignore();
		for(int i = 0; i < n; i++) {
			gets(filled[i]);
			}
		cout << query() << '\n';
	}
	return 0;
} 
