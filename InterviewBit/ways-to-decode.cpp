int Solution::numDecodings(string A) {
    if(A == "") return 0;
    int len = A.size();
    int *dp = new int[len+1];
    memset(dp, 0, sizeof(int)*(len+1));
    dp[0] = 1;
    dp[1] = (A[0] != '0')? 1 : 0;
    for(int i = 2; i <= len; i++){
        int f = (A[i-1] - '0');
        int s = (A[i-2] - '0')*10 + f;
        if(f > 0 && f < 10) dp[i] += dp[i-1];
        if(s > 9 && s < 27) dp[i] += dp[i-2];
    }
    return dp[len];
}
