int Solution::solve(const vector<int> &A) {
    int len = A.size(), diff, x, pos, ans = 1;
    int dp[1000][1000];
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            dp[i][j] = 2;
            diff = A[j] - A[i];
            x = 2*A[i] - A[j];
            pos = -1;
            for(int k = 0; k < i; k++){
                if(x == A[k]){
                    pos = k; 
                }
            }
            if(pos != -1) {
                dp[i][j] = dp[pos][i] + 1;
            }
            ans = max(dp[i][j], ans);
        }
    }
    return ans;
}