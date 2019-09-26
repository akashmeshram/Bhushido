//562 - Dividing coins
#include<bits/stdc++.h>
using namespace std;

int n, m, sum, total;
int arr[100], dp[100][500];

int kval(int id, int lft){
	int &ans = dp[id][lft];
	if(ans != -1) return ans;
	if(id == m || lft == 0) {
		ans = 0;
	}
	else{
		if(lft < arr[id]) ans = kval(id+1, lft);
		else ans = max(kval(id+1, lft), arr[id] + kval(id+1, lft - arr[id]));		
	}
	return ans;
}

int main(){
	cin >> n;
	while(cin >> m){
		memset(arr, 0, sizeof arr);
		memset(dp, -1, sizeof dp);
		total = 0;
		for(int i = 0; i < m; i++){
			cin >> *(arr + i);
			total += *(arr + i);
		}
		sum = total/2;
		cout << total - sum - kval(0, sum);
		puts("");
	}

	return 0;
}
