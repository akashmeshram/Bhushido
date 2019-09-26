//UVa 673 - Parentheses Balance
#include<bits/stdc++.h>
using namespace std;

bool check() {
	char stack[129];
	char arr[129];
	cin >> arr;
	int idx = -1;
	for(int i = 0; arr[i]; i++) {
		if(arr[i] == ']') {
			if(idx < 0) return false;
			if(stack[idx] != '[') {
				return false;
			}
			idx--;
		} else if(arr[i] == ')') {
			if(idx < 0) return false;
			if(stack[idx] != '(') {
				return false;
			}
			idx--;
		} else {
			stack[++idx] = arr[i];
		}
	}
	if(idx == -1) {
		return true;
	}
}

int main() {
	int n;
	cin >> n;
	while(n--) {
		if(check()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
