bool parity(long long int n) {
    bool res = 0;
    while(n) {
        res ^= 1;
        n &= (n-1);
    }
    return res;
}