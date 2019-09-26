//UVa 103 - Stacking Boxes
#include<bits/stdc++.h>
using namespace std;

int data[30][10];
int k, n, LIS[20], ans[30];

static int cmp(const void* a, const void* b) {
	int* arr1 = (int*)a;
  	int* arr2 = (int*)b;
	for(int i = 0; i < n; i++) {
		if(arr1[i] > arr2[i]) return 1;
		else if(arr1[i] < arr2[i]) return 0;
	}
	return 0;
}

bool check(int a, int b) {
	for(int j = 0; j < n; j++) {
		if(data[a][j] < data[b][j]) return false;
	}
	return true;	
}

int calis() {
	int val, id = 0;
	for(int i = 0; i < k; i++) {
		val = 1;
		for(int j = 0; j < i; j++) {
			if(check(i, j)) {
				if(val < LIS[j] + 1) {
					val = LIS[j] + 1;
				}
			}
		}
		LIS[i] = val;
	}
}

int main() {
	while(scanf("%d %d", &k, &n) == 2) {
		memset(LIS, 0, sizeof(LIS));
		memset(ans, -1, sizeof(ans));
		for(int i = 0; i < k; i++) {
			for(int j = 0; j < n; j++) {
				cin >> data[i][j];
			}
			sort(data[i], data[i] + n);
		}
		qsort(data, k, sizeof(data[0]), cmp);
		calis();
		cout << LIS[k-1] << "\n";
	}
	return 0;
} 
