//UVa 837 - Light and Transparencies 
#include<bits/stdc++.h>
using namespace std;

int main() {
	int cases, NL, i, j, k;
	cin >> cases;
	double coeff, mid, _, __;
	double points[200];
	double val[100];
	double L[100], R[100];
	while(cases--) {
		cin >> NL;		
		for(i = 0 ; i < NL; i++){
			cin >> points[i] >> _ >> points[NL + i] >> __ >> val[i];
			L[i] = points[i];
			R[i] = points[NL + i];
		}
		sort(points, points + NL*2);
		cout << NL*2 + 1 << "\n";
		printf("-inf %.3lf 1.000 \n", points[0]);
		for(j = 0 ; j < NL*2 - 1; j++){
			mid = (points[j + 1] + points[j]) / 2;
			coeff = 1;
			for(k = 0; k < NL; k++) {
				if(mid > L[k] && mid < R[k] || mid < L[k] && mid > R[k]) coeff *= val[k] ;
			}
			printf("%.3lf %.3lf %.3lf \n", points[j], points[j + 1], coeff);
		}
		printf("%.3lf +inf 1.000 \n\n", points[j]);
	}	
	return 0;
}
