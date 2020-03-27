unsigned long closeInt(unsigned long n) {
    short i = 0;
    while(((n >> i) & 1) == ((n >> (i+1)) & 1)) i++;
    if(i == 63) return n;
    unsigned long mask = (1UL << i) | (1UL << i+1);
    n ^=  mask;
    return n;
}