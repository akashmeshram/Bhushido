//UVa 739 - Soundex Indexing
#include<bits/stdc++.h>
using namespace std;

int main() {
	char word[20];
	char code[27] = "01230120022455012623010202";
	int count;
	while(gets(word)) {
		char ans[5] = "0000";
		count = 1;
		ans[0] = word[0];
		for(int i = 1; word[i] != '\0'; i++) {
			if(code[word[i] - 'A'] != '0' && count < 4) {
				if(code[word[i] - 'A'] != code[word[i-1] - 'A']){
					ans[count++] = code[word[i] - 'A'];
				}
			}
		}
		cout << ans << "\n";
	} 
	
	return 0;
}
