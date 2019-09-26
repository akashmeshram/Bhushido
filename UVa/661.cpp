//UVa 661 - Blowing Fuses
#include<bits/stdc++.h>
using namespace std;

typedef map<int, bool> dev;
typedef map<int, int> eng;

int main() {
	int n, m, c, power, d, max, count = 0;
	int i, j;
	bool blown;
	dev Dev;
	eng Eng;
	while(true) {
		power = 0;
		max = -1;
		blown = false;
		cin >> n >> m >> c;
		if(n == 0) break;
		cout << "Sequence " << ++count << "\n";
		for(i = 0; i < n; i++) {
			Dev[i] = false;
		}
		for(j = 0; j < n; j++) {
			cin >> Eng[j];
		}
		while(m--) {
			cin >> d;
			if(!Dev[d-1]) {
				power += Eng[d-1]; 
			} else {
				power -= Eng[d-1];
			}
			if(max < power) max = power;
			Dev[d-1] = !Dev[d-1];
			if(power > c) blown = true; 
		}
		if(blown) {
			cout << "Fuse was blown.\n\n";
		} else {
			cout << "Fuse was not blown.\n";
			cout << "Maximal power consumption was " << max << " amperes.\n\n";
		}
	}
	return 0;

}
