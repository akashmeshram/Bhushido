//UVa 231 - Testing the Catcher 
#include<bits/stdc++.h>
using namespace std;

int cnt, arr[32767], ans[32767], temp;

void lis() {
	for(int i = 0; i < cnt; i++) {
		temp = 1;
		for(int j = 0; j < i; j++) {
			if(arr[i] <  arr[j]) {
				temp = max(temp, ans[j] + 1);
			}
		}
		ans[i] = temp;
	}
	cout << ans[cnt-1] << '\n';
}

int main() {
	int n, m;
	while(true) {
		cnt = 0;
		cin >> n;
		if(n == -1) break;
		arr[cnt++] = n;
		while(true) {
			cin >> m;
			if(m == -1) break;
			arr[cnt++] = m;
		}
		lis();
	}
	return 0;
} 
