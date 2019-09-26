// UVa 441 - Lotto
#include<bits/stdc++.h>
using namespace std;
         
int main() {
	int n, arr[13];
	int a, b, c, d, e, f;
	while(scanf("%d", &n) && n != 0) {
		for(int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for(a = 0; a < n-5; a++){
			for(b = a+1; b < n-4; b++){
				for(c = b+1; c < n-3; c++){
					for(d = c+1; d < n-2; d++){
						for(e = d+1; e < n-1; e++){
							for(f = e+1; f < n; f++){
								printf("%d %d %d %d %d %d\n", arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
							}
						}
					}
				}
			}
		}
		printf("\n");
	}	
	return 0;
} 
