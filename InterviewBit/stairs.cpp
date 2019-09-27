int Solution::climbStairs(int A) {
    int cval[36] = {-1};
    cval[1] = 1;
    cval[2] = 2;
    for(int i = 3; i <= A; i++) cval[i] = cval[i-1] + cval[i-2];
    return cval[A];
}
