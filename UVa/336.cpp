//UVa 336 - A Node Too Far
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, node, idx, idy, st, ttl, reached, Case = 0;
	
	while(scanf("%d", &n), n != 0) {
		node = 0;
		map<int, int> nodeList;
		vector<int> linkNode[30];
		for(int i = 0; i < n; i++) {
			cin >> a >> b;
			if(nodeList[a] == 0) nodeList[a] = ++node;
			if(nodeList[b] == 0) nodeList[b] = ++node;
			idx = nodeList[a];
			idy = nodeList[b];
			linkNode[idx].push_back(idy);
			linkNode[idy].push_back(idx);
		}
		while(scanf("%d %d", &st, &ttl), st != 0) {
			queue<int> qBFS;
			int reach[40] = {0};
			reached = 0;
			idx = nodeList[st];
			qBFS.push(idx);
			reach[idx] = 1;
			while(!qBFS.empty()) {
				idy = qBFS.front();
				qBFS.pop();
				if(reach[idy] > ttl) continue;
				for(vector<int>::iterator i = linkNode[idy].begin(); i != linkNode[idy].end(); i++) {
					if(!reach[*i]) {
						qBFS.push(*i);
						reach[*i] = reach[idy] + 1;
						reached++;	
					}					
				}
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++Case, node - reached - 1, st, ttl);
		}
	}
	return 0;
}
