int Solution::uniquePaths(int A, int B) {
    int dp[A][B];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 0; i < A; i++){
        for(int j = 0; j < B; j++){
            if(i - 1 >= 0) dp[i][j] += dp[i-1][j];
            if(j - 1 >= 0) dp[i][j] += dp[i][j-1];
        }
    }
    return dp[A-1][B-1];
}