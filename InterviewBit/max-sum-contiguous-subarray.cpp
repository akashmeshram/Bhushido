int Solution::maxSubArray(const vector<int> &A) {
    int len = A.size();
    if(len == 1) return A[0];
    int ans = -1000000000, sum = 0;
    for(int i = 0; i < len; i++){
        sum += A[i];
        ans = max(sum, ans);
        if(sum < 0) sum = 0;
    }
    return ans;
}