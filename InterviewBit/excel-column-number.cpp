int Solution::titleToNumber(string A) {
    int ans = 0, len = A.size();
    for(int i = 0; i < len; i++){
        ans += pow(26,i)*(A[len-1-i] - '@');
    }
    return ans;
}
