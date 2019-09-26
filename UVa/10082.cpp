//UVa 10082 - WERTYU
#include<bits/stdc++.h>
using namespace std;

typedef map<char, int> dict;

char alpha[]={"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};

int main() {
	string line;
	dict mapper;
	for(int i = 1; i < strlen(alpha); i++) {
		mapper[alpha[i]] = i-1;
	}
	mapper[alpha[0]] = strlen(alpha) - 1;
	while(getline(cin, line)) {
		for(string::iterator iter = line.begin(); iter != line.end(); ++iter) {
			if(*iter != ' '){
				cout << alpha[mapper[*iter]];
			} else {
				cout << " ";
			}
		}
		cout << '\n';
	}

	return 0;
}
