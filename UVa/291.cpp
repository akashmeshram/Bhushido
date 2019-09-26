//UVa 291 - The House of Santa Claus
#include<bits/stdc++.h>
using namespace std;

int house[5][5] = {
	{0,1,1,0,1},
    {1,0,1,0,1},
    {1,1,0,1,1},
    {0,0,1,0,1},
    {1,1,1,1,0}
};

int ans[8] = {0};

void dfs(int idx, int num) {
	int i;
	ans[idx] = num;
	if(idx == 8) {
		for(i = 0; i <= 8; i++) {
			printf("%d", ans[i] + 1);
		}
		printf("\n");
		return;
	}
	for(i = 0; i < 5; i++) {
		if(house[num][i] == 1) {
			house[num][i] = house[i][num] = 0;
			dfs(idx + 1, i);
			house[num][i] = house[i][num] = 1;
		}
	}
}

int main() {
	dfs(0, 0);
	return 0;
}
