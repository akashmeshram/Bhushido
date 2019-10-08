int Solution::trailingZeroes(int A) {
    int n = 0, k = 1, i = 1;
    while(k > 0){
        k = A/pow(5,i++);
        n += k;
    }
    return n;
}
