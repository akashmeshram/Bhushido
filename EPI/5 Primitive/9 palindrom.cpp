bool palindrom(int n){
    bool ans = 0;
    while(n){
        int b = n%10;
        int a = n;
        int k = 1;
        while(a > 10) {
            a /= 10;
            k*=10;
        }
        if(a != b) {
            return false;
        }
        n = n - a*k;
        n /= 10;
    }
    return true;
}