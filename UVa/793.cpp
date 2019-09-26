//UVa 793 - Network Connections
#include<bits/stdc++.h>
using namespace std;

vector<int> pset(1000);

void initSet(int size) {
	pset.resize(size);
	for(int i = 0; i < size; i++) {
		pset[i] = i;
	}
}

int findParent(int num) {
	if(pset[num] == num) {
		return num;
	} else {
		return findParent(pset[num]);
	}
}

void unionSet(int a, int b) {
	pset[findParent(a)] = findParent(b);
}

bool sameSet(int a, int b) {
	return (findParent(a) == findParent(b));
}

int main() {
	int n, dev, succ, unsucc;
	string line;
	cin >> n;
	while(n--) {
		cin >> dev;
		cin.ignore();
		succ = 0, unsucc = 0;
		initSet(dev);
		while(getline(cin, line) && line != "") {
			if(line[0] == 'c') {
				unionSet(line[2] - '1', line[4] - '1');
			} else if(line[0] == 'q') {
				if(sameSet(line[2] - '1', line[4] - '1')) {
					succ++;
				} else {
					unsucc++;
				}
			}
		}
		printf("%d,%d\n\n", succ, unsucc);
	}
	
	return 0;
}
