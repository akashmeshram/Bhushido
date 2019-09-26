// 332 - Rational Numbers from Repeating Fractions
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return (b == 0)? a: gcd(b, a % b); }

int main() {
    int j, k, nu, de, gc;
    float num;

    while(scanf("%d %f", &j, &num) == 2) {
        k = 0;
        while(true) {
            k++;
            num *= 10;
            if(num - floor(num) == 0) break;
        }
        nu = int(num) - floor(num/pow(10, j));
        de = pow(10, k) - pow(10, k-j);
        gc = gcd(de, nu);
        nu /= gc, de /= gc;
        printf("Case: %d/%d\n", nu, de);
    }

    return 0;
}
