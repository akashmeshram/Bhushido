int Solution::solve(int A, int B) {
    vector<int> row(B+1, 0);
    vector<vector<int> > dp(A, row);
    for(int i = 1; i < 10; i++) {
        if(B - i >= 0) dp[0][B - i] = 1;
    }
    for(int i = 1; i < A; i++){
        for(int s = 0; s <= B; s++){
            if(dp[i-1][s] == -1) continue; 
            for(int n = 0; n < 10; n++){
                if(s - n >= 0) {
                    dp[i][s-n] = (dp[i][s-n] + dp[i-1][s]) % 1000000007;
                }
            }
        }
    }
    return dp[A-1][0];
}