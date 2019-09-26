//836 - Largest Submatrix
#include<bits/stdc++.h>
using namespace std; 

#define INF -625; 

int arr[25][25];

int main(){
	int n, cnt, ans;
	string line;
	scanf("%d", &n);
	cin.ignore();
	while(n--){
		cnt = 0;
		ans = 0;
		memset(arr, 0, sizeof arr);
		while(getline(cin, line) && line[0] != '\n'){
			for(int i = 0; line[i]; i++) {
				arr[cnt][i] = (line[i] - '0')? 1 : INF;				
			}
			cnt++;
		}
		for(int i = 0; i < cnt; i++){
			for(int j = 0; j < cnt; j++){
				if(i > 0) arr[i][j] += arr[i-1][j];
				if(j > 0) arr[i][j] += arr[i][j-1];
				if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
			}
		}
		for(int i = 0; i < cnt; i++){
			for(int j = 0; j < cnt; j++){
				for(int k = i; k < cnt; k++){
					for(int l = j; l < cnt; l++){
						ans = max(ans, arr[k][l] - arr[i][l] - arr[k][j] + arr[i][j]);
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
