//UVa 410
#include<bits/stdc++.h>
using namespace std;

int c[10][2], s[20];
int nC, nS, cnt = 0;
float sum, imb;

void simulate() {
	sort(s, s + 2*nC);
	for(int i = 0; i < nC; i++) {
		c[i][0] = s[i];
		c[i][1] = s[2*nC - i - 1];
	}		
	
	cout << "Set #" << cnt << '\n';
	for(int i = 0; i < nC; i++) {
		cout << i << ": ";
		if(c[i][0]) cout << c[i][0] << " ";
		if(c[i][1]) cout << c[i][1] << " ";
		cout << '\n';
		imb += abs(sum/nC - c[i][0] - c[i][1]);
	}
	printf("IMBALANCE = %.6f\n", imb);
}

int main() {
	while(scanf("%d %d", &nC, &nS) == 2) {
		sum = 0;
		imb = 0;
		cnt++;
		memset(s, 0, sizeof(s));
		memset(c, -1, sizeof(c[0][0])*10*2);
		for(int i = 0; i < nS; i++) {
			scanf("%d", &s[i]);
			sum += s[i];
		}
		simulate();
		cout << '\n';
	}
	return 0;
} 
