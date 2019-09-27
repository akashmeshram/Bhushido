int Solution::longestSubsequenceLength(const vector<int> &A) {
    int len = A.size();
    int anl, anr;
    int larr[3000] = {0}, rarr[3000] = {0};
    for(int i = 0; i < len; i++){
        anl = 1;
        anr = 1;
        for(int j = 0; j < i; j++){
            if(A[i] > A[j]) anl = max(anl, larr[j] + 1);
        }
        larr[i] = anl;
        for(int k = len - 1; k > len - i - 1; k--){
            if(A[k] < A[len - i - 1]) anr = max(anr, rarr[k] + 1);
        }
        rarr[len - i - 1] = anr;
    }
    int ans = 0;
    for(int i = 0; i < len; i++){
        ans = max(ans, larr[i] + rarr[i] - 1);
    }
    return ans;
}