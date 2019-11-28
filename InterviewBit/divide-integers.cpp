int Solution::divide(int A, int B) {
    if(A==0) return 0;
    if(B==1) return A;
    int sign = (A < 0 ^ B < 0)? -1 : 1;
    A = abs(A), B = abs(B);
    int ans = -1;
    while(A >= 0){
        if(ans == INT_MAX - 1) return  INT_MAX;
        A -= B;
        ans++;
    }
    return sign*ans;
}