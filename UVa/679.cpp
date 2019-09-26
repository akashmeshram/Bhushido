//UVa 679 - Dropping Balls
#include<bits/stdc++.h>
using namespace std;

int depth, ball, node;

void query() {
	node = 1;
	while(node*2 <= depth) {
		if(ball % 2 == 0) {
			node = node*2 + 1;
		} else {
			node = node*2;
		}
		ball = (ball + 1)/2;
	}
}

int main() {
	int cse;
	scanf("%d", &cse);
	while(cse--){
		scanf("%d %d", &depth, &ball);
		depth = (1<<depth) -1;
		query();
		printf("%d\n", node);
	}
	return 0;
} 
