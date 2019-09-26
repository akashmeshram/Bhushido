//UVa 11235 - Frequent Values
#include<bits/stdc++.h>
using namespace std;

int xs = 100000;

vector<int> tree(400000);

int data[100000];
int cnt[200000];
int bound[200000];

int u, v;

void initTree(int N) {
	int len =  (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
	tree.resize(len);
}

void makeTree(int n, int a, int b) {
	int mid = (a + b)/2;
	if( a == b) {
		tree[n] = cnt[data[a]];
		return;
	} 
	makeTree(2*n, a, mid);
	makeTree(2*n + 1, mid + 1, b);
	tree[n] = max(tree[2*n], tree[2*n + 1]);	

}

int query(int node, int m, int n) {
	if(u > n || v < m) {
		return -1;
	}
	if(m >= u && n <= v) {
		return tree[node];
	}

	int l = query(node*2, m, (m + n)/2);
	int r = query(node*2 + 1, (m + n)/2 + 1, n);

	if(l == -1) return r;
	if(r == -1) return l;

	return max(l, r);
}
         
int main() {
	int n, q, len, i, j, ans1, ans2, ans3;
	memset(data, 0, sizeof(data));
	memset(cnt, 0, sizeof(cnt));
	memset(bound, 0, sizeof(bound));
	cin >> n >> q;
	for(i = 0; i < n; i++) {
		cin >> data[i];
		data[i] += xs;
		cnt[data[i]]++;
		if(cnt[data[i]] == 1) bound[data[i]] = i;
	}
	initTree(n);
	makeTree(1, 0, n-1);
	for(i = 0; i < q; i++) {
		cin >> u >> v;
		u -= 1;
		v -= 1;
		ans1 = cnt[data[u]] + bound[data[u]] - u;
		if(ans1 > v - u) ans1 = (v-u); 
		ans2 = 1 + v - bound[data[v]];
		if(ans2 > v - u) ans2 = (v-u);
		u = cnt[data[u]] + bound[data[u]];
		v = bound[data[v]] - 1;
		ans3 = query(1, 0, n-1);
		cout << max(max(ans1, ans2), ans3) << '\n';
	}
	return 0;
} 
