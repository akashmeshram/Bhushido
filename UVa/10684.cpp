//10684 - The jackpot
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, ans, crr, p;
	while(scanf("%d", &n) == 1 && n){
		ans = 0, crr = 0;
		while(n--){
			scanf("%d", &p);
			crr += p;
			ans = max(crr, ans);
			if(crr < 0) {
				crr = 0;
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}
