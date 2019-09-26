// UVa 154 - Recyling
#include<bits/stdc++.h>
using namespace std;

int city[100][5], res, cnt = 0;

int mapChar(char c) {
	if(c == 'r') return 0;
	if(c == 'o') return 1;
	if(c == 'y') return 2;
	if(c == 'g') return 3;
	if(c == 'b') return 4;

	return -1;
}

void query() {
	int max = 100000, ans;
	for(int i = 0; i < cnt; i++) {
		ans = 0;
		for(int j = 0; j < cnt; j++) {
			if(i == j) continue;
			for(int k = 0; k < 5; k++) {
				if(city[i][k] != city[j][k]) ans++;
			}
		}
		if(ans < max) res = i + 1, max = ans;
	}
}

         
int main() {
	string line;
	while(getline(cin, line) && line[0] != '#') {
		if(line[0] != 'e'){
			for(int i = 0; i < 20; i+=4) {
				city[cnt][mapChar(line[i])] = line[i + 2];
			}
			cnt++;			
		} else {
			query();
			cout << res << '\n';
			cnt = 0;
		}
	}
	return 0;
} 
