//UVa 573 - The Snail
#include<bits/stdc++.h>
using namespace std;

int main() {
	int h, d, day;
	float u, dist, f;
	while(true){
		dist = 0.0;
		day = 1;
		cin >> h >> u >> d >> f;
		if(h == 0){
			break;
		}
		f = f*u/100;
		while(true) {		
			dist += u;
			if(dist > 0) {
				u -= f;
			}
			day++;
			if(dist > h){
				cout << "success on day " << day << "\n";
				break;
			}
			dist -= d;
			if(dist < 0){
				cout << "failure on day " << day << "\n";
				break;
			}			
		
		}		
	}
	return 0;

}
