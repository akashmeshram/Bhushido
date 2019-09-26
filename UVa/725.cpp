// UVa 725 - Division 
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int num, count[10], i, j;
	char total[11];
	bool flag, res;
	while(scanf("%d", &num) && num) {
		res = true;
		for(i = 1234; i < 100000/num ; i++) {
			flag = true;
			memset(count, 0, sizeof(count));
			sprintf(total, "%05d", i);
			sprintf(total + 5, "%05d", i*num);
			for(j = 0; j < 10; j++) count[total[j] - '0']++;
			for(j = 0; j < 10; j++) if(!count[j]) {flag = false; break;}
			if(flag) {
				res = false;
				printf("%05d / %05d = %d\n", i*num, i, num);
			}
		}
		if(res) printf("There are no solutions for %d.\n", num);
		puts("");
	}
	return 0;
} 
