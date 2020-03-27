short countBits(long long int n) {
    short res = 0;
    while(n) {
        res++;
        n &= (n-1);
    }
    return res;
}