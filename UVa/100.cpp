//100 The 3n + 1 problem
#include<bits/stdc++.h>
using namespace std;


int cycle(int num){
	int count = 1;
	while(num !=1) {
		count++;
		if(num & 1 ){
			num = 3*num + 1;
		} else {
			num = num / 2;			
		}
	}
	return count;
	
};

int main() {
	int a, b, max;
	while(scanf("%d %d", &a, &b) != EOF){
		max= -1;
		for(int i = a; i <= b; i++){		
			int res = cycle(i);
			max = (max > res)? max: res;
		}
		printf("%d %d %d\n", a, b, max);
	}	
	exit (0);		
}
