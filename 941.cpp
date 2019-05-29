//UVa 941 - Permutations
#include<bits/stdc++.h>
using namespace std;

long long factorial[21] = {1,1};

void permutation(char* word, long long perm) {
	int size = strlen(word), c;
	for(int pos = 0; pos < size; pos++) {
		if(perm <= 0) return;
		sort(word + pos, word + size);
		for(c = 0; c < size - pos; c++) {
			if(perm < (c+1)*factorial[size - pos - 1]) {
				swap(word[pos], word[pos + c]);
				perm = perm - (c)*factorial[size - pos - 1];
				break;
			}
		}
	}
}

int main() {
	int n;
	long long perm;
	char alpha[20];
	cin >> n;
	for(int i = 2; i <= 20; i++) {
		factorial[i] = factorial[i-1]*i; 
	}

	while(n--) {
		cin >> alpha;
		cin >> perm;		
		permutation(alpha, perm);
		cout << alpha << '\n';		
	}
	return 0;
}
