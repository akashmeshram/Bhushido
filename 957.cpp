//UVa 957 - Popes
#include<bits/stdc++.h>
using namespace std;

int popes[100];
int Y, P, flag, L, R, ans = 0, rL, rR;

void bsearch(int a, int b) {

	if(popes[b] < flag) {
		R = b;
		if(ans < (R - L + 1)) {
			rL = L, rR = R;
			ans = R - L + 1;
		}
		return;
	}

	int mid = (a + b) / 2;
	while(popes[mid] == popes[mid + 1]) mid++;

	if(popes[mid] == flag) {
		R = mid;
		if(ans < (R - L + 1)) {
			rL = L, rR = R;
			ans = R - L + 1;
		}
		return;
	} else 
	if(popes[mid] > flag) {
		while(popes[mid] == popes[mid - 1]) mid--;
		bsearch(a, mid - 1);
	} else 
	if(popes[mid] < flag) {
		bsearch(mid + 1, b);
	}
}


int main() {
	scanf("%d %d", &Y, &P);
	for(int i = 0; i < P; i++) {
		scanf("%d", &popes[i]);
	}
	L = 0;
	while(L < P - Y + 1) {
		flag = popes[L] + Y - 1;
		bsearch(L + 1, P - 1);
		L++;
	}
	printf("%d %d %d\n", ans, popes[rL], popes[rR]);
	return 0;
} 
