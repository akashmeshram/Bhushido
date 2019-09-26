//UVa 459 - Graph Connectivity
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> node;
vector<node> Graph;
vector<int> visit;

void serach(int num) {
	node branch = Graph[num];
	visit[num] = 1;
	for(vector<int>::iterator ptr = branch.begin(); ptr != branch.end(); ptr++) {
		if(!visit[*ptr]) {
			serach(*ptr);	
		}		
	}
}

int main() {
	int n, total, mx;
	char lnode;
	string val;
	cin >> n;

	while(n--) {
		mx = 0;
		cin >> lnode;
		cin.ignore();
		total = lnode - 'A' + 1;
		Graph.resize(total);
		visit.resize(total, 0);
		while(getline(cin, val) && val != "") {
			Graph[val[0] - 'A'].push_back(val[1] - 'A');
			Graph[val[1] - 'A'].push_back(val[0] - 'A');
		}

		for(int i = 0; i < total; i++) {
			if(!visit[i]) {
				mx++;
				serach(i);
			}
		}

		cout << mx << '\n';

	}
	return 0;
}
