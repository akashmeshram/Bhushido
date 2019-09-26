//UVa 483 - Word Scramble
#include<bits/stdc++.h>
using namespace std;

int main() {
	char c[1000];
	while(gets(c)){
		int i, j;
		int start = -1, end = -1;
		for(i = 0; c[i]; i++){
			start = i; end = i;
			while(c[end] != ' ' && c[end] != '\0') end++;
			for(j = end-1; j >= start; j--) {
				cout << c[j];
			}
			if(c[end] != '\0') {
				cout << " ";
			}
			i = end;
		}
		cout << "\n";
	}
	exit (0);		
}
