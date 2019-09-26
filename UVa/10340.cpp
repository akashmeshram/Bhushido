//UVa 10340 - All in All
#include<bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	int i, j;
	while(cin >> s >> t) {
		i = 0;
		for(j=0; t[j] && s[i]; j++) {
			if(t[j] == s[i]) {
				i++;
			}
		}
		if(s[i] == '\0') {
			printf("Yes\n");
		} else {
			printf("No\n");
		}

	} 
	return 0;
} 
