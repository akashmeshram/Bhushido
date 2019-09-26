//UVa 11462 - Age Sort
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n , age[101] = {0}, person;
	while(1) {
		cin >> n;
		if(n == 0) break;
		while(n--) {
			cin >> person;
			age[person]++;
		}
		for(int i = 1 ; i <= 100; i++) {
			while(age[i] != 0) {
				cout << i << " ";
				age[i]--;
			}
		}
		cout << '\n' ;
	}
	return 0;
}
