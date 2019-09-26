//UVa 524 - Prime Ring Problem
#include<bits/stdc++.h>
using namespace std;

int n, cnt, cse = 0;
int num[16], ans[16];

bool checkprime(int num) {
	for(int i = 2; i < num / 2; i++) {
		if(num % i == 0) return false;
	}
	return true ;
}

void search(int k) {
	if(cnt == n) {
		if(!checkprime(ans[0] + ans[n-1] + 2)) return;
		for(int i = 0; i < n; i++) {
			cout << ans[i] + 1 << " ";
		}
		puts("");
		return;
	}
	
	for(int i = 0; i < n; i++) {
		if(num[i] != 1 && checkprime(k + i + 2)) {
			num[i] = 1;
			ans[cnt++] = i;
			search(i);
			cnt--;
			num[i] = 0;
		}
	}
}

int main() {
	while(scanf("%d", &n) == 1){		
		printf("Case %d:\n", ++cse);
		cnt = 0;
		memset(num, 0, sizeof(num));
		memset(ans, 0, sizeof(ans));
		num[0] = 1;
		ans[cnt++] = 0;
		search(0);
		puts("");
	}	
	return 0;
} 
