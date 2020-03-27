long long swap(long long n, short x, short y) {
    if((n >> x) & 1 && (n >> y) & 1) {
        return n;
    }
    long long mask = (1LL << x) | (1LL << y);
    n ^= mask;
    return n;
}