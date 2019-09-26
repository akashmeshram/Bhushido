//UVa 727 - Equation 
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, len, idx; 
	char arr[50], ch[2], stack[50];
	scanf("%d \n", &n);
	while(n--) {
		len = -1;
		idx = -1;
		while(gets(ch)) {
			if(strlen(ch) == 0) break;
			arr[++len] = ch[0];
		}

		for(int i = 0; arr[i]; i++) {

			if(arr[i] == '(') {
				stack[++idx] = arr[i];
			} else 

			if(arr[i] == ')') {
				while(arr[idx] != '(') {
						cout << stack[idx--];
					}
				idx--;
			} else 

			if(arr[i] == '*' || arr[i] == '/') {
				stack[++idx] = arr[i];
			} else 

			if(arr[i] == '+' || arr[i] == '-') {
				if(stack[idx] == '*' || stack[idx] == '/') {
					while(idx != -1 || arr[idx] != '(') {
						cout << stack[idx--];
					}					
				}
				stack[++idx] = arr[i];
			} else 

			{
				cout << arr[i];
			}
		}

		while(idx != -1 ) {
			cout << stack[idx--];
		}

	}
	return 0;
}
