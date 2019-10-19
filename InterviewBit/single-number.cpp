int Solution::singleNumber(const vector<int> &A) {
    int ans = 0, len = A.size();
    for(int i = 0; i < len; i++) ans ^= A[i];
    return ans;
}