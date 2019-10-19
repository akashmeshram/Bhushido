int Solution::findMinXor(vector<int> &A) {
    int ans = 1000000;
    sort(A.begin(), A.end());
    int len = A.size();
    for(int i = 0; i < len - 1; i++) ans = min(ans, A[i] ^ A[i + 1]);
    return ans;
}
