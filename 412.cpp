// 412 - Pi
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {return (b==0)? a: gcd(b, a%b);}

int main() {
    int n, count;
    int arr[51];
    while(scanf("%d", &n) == 1 && n != 0) {
        count = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(gcd(arr[j], arr[i]) == 1) {
                    count++;
                }
            }
        }
        if(count == 0) {
            puts("No estimate for this data set.");
        } else {
            printf("%f\n", sqrt(3*n*(n-1)*1.0/count));
        }
    }

    return 0;
}
