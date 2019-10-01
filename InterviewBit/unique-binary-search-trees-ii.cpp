int dp[19][19];

int getTree(int st, int ed){
    if(st > ed) return 1;
    if(dp[st][ed] != -1) return dp[st][ed];
    int lf = 0, rt = 0, ans = 0;
    for(int i = st; i <= ed; i++){
        lf = getTree(st, i-1);
        rt = getTree(i + 1, ed);
        ans += lf*rt;
    }
    dp[st][ed] = ans;
    return ans;
}

int Solution::numTrees(int A) {
    if(A == 1) return 1;
    if(A == 2) return 2;
    memset(dp, -1, sizeof dp);
    dp[0][-1] = dp[0][0] = 1;
    for(int i = 0; i < A-1; i++){
        dp[i][i+1] = 2;
        dp[i+1][i] = dp[i+1][i+1] = 1;
    }
    for(int j = 0; j < A-2; j++){
        dp[j][j+2] = 5;
    }
    return getTree(0, A-1);
}
