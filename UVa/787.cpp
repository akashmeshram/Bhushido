//787 - Maximum Sub-sequence Product
#include<bits/stdc++.h>
using namespace std;

int main(){
	bool flagp = false, flagn = false;
	int cnt = 0, n, temp;
	int maxP = 1, minP = 1, ans = -999999;

	while(scanf("%d", &n) == 1){
		if(n == -999999) {
			printf("%d\n", ans);
			maxP = 1, minP = 1, ans = -999999;
			continue;
		}
		flagp = false, flagn = false;
		if(n > 0){
			flagp = true;
			maxP = maxP*n;
			minP = min(minP*n, 1);
		} else 
		if(n == 0){
			if(ans < 0) ans = 0;
			maxP = 1;
			minP = 1;
		} else {
			flagn = true;
			temp = maxP;
			maxP = max(minP*n, 1);
			minP = temp*n;
		}
		
		if(ans < maxP && maxP != 1 && flagn) ans = maxP;
		else if(ans < maxP && flagp) ans = maxP;
		else if(ans < minP && flagn) ans = minP;		

	}

	return 0;
}
