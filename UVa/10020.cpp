//UVa 10020 - Minimal Coverage
#include<bits/stdc++.h>
using namespace std;

typedef struct {
	int x1;
	int x2;
} seg;

int cmp(const void *a, const void *b) {
	seg *i, *j;
	i = (seg *)a, j = (seg *)b;
	if(i -> x1 != j -> x1) {
		return i -> x1 - j -> x1;
	}
	return j -> x2 - i -> x2;
}

int main() {
	int c;
	int m, s1, s2, total;
	seg xseg[1000];
	seg ans[1000];
	cin >> c;
	while(c--) {
		total = 0;
		cin >> m;
		while(scanf("%d %d", &s1, &s2) == 2 ) {
			if(s1 == 0 && s2 == 0) break;
			xseg[total].x1 = s1, xseg[total++].x2 = s2; 
		}
		qsort(xseg, total, sizeof(seg), cmp);
		int p1 = 0, p2 = 0, anslen = 0, i = 0, j;
		while(i < total) {
			p1 = p2;
			j = -1;
			while(i < total && xseg[i].x1 <= p1) {
				if(xseg[i].x2 > p2) {
					p2 = xseg[i].x2;
					j = i;
				}
				i++;
			}
			if(j == -1) {
				if(p1 < m) anslen = 0;
				break;
			}
			ans[anslen++] = xseg[j];
			if(p2 > m) break;
			i = j + 1;
		}
		if(anslen == 0) {
			puts("0\n");
			continue;
		}
		cout << m << '\n';
		for(int k = 0; k < anslen; k++) {
			cout << ans[k].x1 << " " << ans[k].x2 << '\n';
		}
		puts("");
	}
	return 0;
} 
