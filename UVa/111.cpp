//111 - History Grading
#include<bits/stdc++.h>
using namespace std;

int correct[20];
int student[20];
int n, m, cnt;

void findlis(){
	int ans, lis[20] = {0};
	for(int i = 0; i < n; i++){
		ans = 1;
		for(int j = 0; j < i; j++){
			if(student[i] > student[j])
			ans = max(ans, lis[j] + 1);
		}
		lis[i] = ans;
	}
	sort(lis, lis + n);
	cout << lis[n-1];
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m;
		correct[m] = i;
	}
	m = 0, cnt = 0;
	while(cin >> m){
		student[cnt] = correct[m];
		cnt++;
		if(cnt == n) {
			cnt = 0;
			findlis();
			memset(student, 0, sizeof student);
		}
	}
	return 0;
}
