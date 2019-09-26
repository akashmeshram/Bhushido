//UVa 10158 - War
#include<bits/stdc++.h>
using namespace std;

int cset[10000];
int size;

void initSet() {
	for(int i = 0; i < size*2; i++) {
		cset[i] = i;
	}
}

int findSet(int num) {
	if(cset[num] == num) {
		return num;
	} else {
		return findSet(cset[num]);
	}
}

void setunion(int a, int b) {
	a = findSet(a), b = findSet(b);
	cset[a] = b;
}

int enemy(int a) {return a + size;}

int main() {
	int op, c1, c2;
	cin >> size;
	initSet();
	while(scanf("%d %d %d", &op, &c1, &c2) == 3) {
		if(op == 0 && c1 == 0 && c2 == 0) break;
		if(op == 1) {
			if(findSet(c1) == findSet(enemy(c2)) || findSet(c2) == findSet(enemy(c1))) {
				cout << -1 << '\n';
			} else {
				setunion(c1, c2);
				setunion(enemy(c1), enemy(c2));
			}
		} else 
		if(op == 2) {
			if(findSet(c1) == findSet(c2) || findSet(enemy(c2)) == findSet(enemy(c1))) {
				cout << -1 << '\n';
			} else {
				setunion(c1, enemy(c2));
				setunion(c2, enemy(c1));
			}
		} else
		if(op == 3) {
			if(findSet(c1) == findSet(c2) || findSet(enemy(c2)) == findSet(enemy(c1))) {
				cout << 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
		} else
		if(op == 4) {
			if(findSet(c1) == findSet(enemy(c2)) || findSet(c2) == findSet(enemy(c1))) {
				cout << 1 << '\n';
			} else {
				cout << 0 << '\n';
			}
		}
	}	
	return 0;
} 
