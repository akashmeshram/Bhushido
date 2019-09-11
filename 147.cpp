//147 - Dollars
#include<bits/stdc++.h>
using namespace std;

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000};
float total;
int ansval[8][30001];

int mval(int id, int val){
	if(id == 8 || val < 0) return 0;
	int &ans = ansval[id][val];
	if(ans != -1) return ans;
	if(val == 0) return 1;
	ans = mval(id + 1, val) + mval(id, val - coins[id]);
	return ans;
}

int main(){
	int n = -1;
	memset(ansval, -1, sizeof ansval);
	while(n++ < 30000){
		ansval[0][n] = mval(0, n);
	}
	while(cin >> total){
		if(total == 0.00) break;
		total = total*100;
		cout << ansval[0][(int) total];
		puts("");
	}
	return 0;
}
