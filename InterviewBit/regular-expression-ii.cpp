int Solution::isMatch(const string A, const string B) {
    int lA = A.size(), lB = B.size();
    bool dp[lA + 1][lB + 1];
    memset(dp, false, sizeof dp);
    dp[0][0] = true;
    char crr;
    if(B[0] == '*'){
        for(int i = 1; i <= lA; i++) dp[0][i] = dp[0][i-1];
    }    
    for(int j = 1; j <= lB; j++){
        if(B[j-1] == '.'){
            for(int i = 1; i <= lA; i++) dp[i][j] = dp[i-1][j-1];
        } else 
        if(B[j-1] == '*'){
            crr = B[j-2];
            for(int  i = 1; i <= lA; i++){
                if(dp[i][j-2] || dp[i][j-1]) dp[i][j] = true;
                else 
                if(crr == A[i-1] || crr == '.') dp[i][j] = dp[i-1][j];
            }
        } else {
            for(int i = 1; i<= lA; i++) if(B[j-1] == A[i-1]) dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[lA][lB];
}
