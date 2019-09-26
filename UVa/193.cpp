//UVa 193 - Graph Coloring 
#include<bits/stdc++.h>
using namespace std;
 
int edge, node, res;
int graph[101][101];
int color[101];
int ans[101];
int nlist[101];

void search(int n) {
	if(n == node) {
		int curres = 0;
		for(int i = 0; i < node; i++) {
			if(color[i]) {
				curres++;
			}
		}
		if(curres > res) {
			res = curres;
			memset(ans, 0, sizeof(ans));
			for(int i = 0; i < node; i++) {
				if(color[i]) {
					ans[i]++;
				}
			}
		}
		return;
	}
	bool black = true;
	for(int i = 0; i < nlist[n]; i++) {
		if(color[graph[n][i]]) {
			black = false;
			break;
		}
	}
	if(black) {
		color[n] = 1;
		search(n+1);
	}
	color[n] = 0;
	search(n+1);
}

int main() {
	int n, a, b;
	cin >> n;
	while(n--) {
		memset(graph, 0, sizeof(graph[0][0]) * 100 * 100);
		memset(color, 0, sizeof(color));
		memset(nlist, 0, sizeof(nlist));
		res = -1;
		cin >> node >> edge;
		for(int j = 0; j < edge; j++) {
			cin >> a >> b;
			graph[a-1][nlist[a-1]++] = b-1;
			graph[b-1][nlist[b-1]++] = a-1;
		}
		search(0);
		cout << res << '\n';
		for(int i = 0; i < node; i++) {
			if(ans[i]) {
				cout << i+1 << " ";	
			}
		}
		puts("");
	}
	return 0;
} 
