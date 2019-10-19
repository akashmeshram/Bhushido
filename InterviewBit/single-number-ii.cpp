int Solution::singleNumber(const vector<int> &A) {
    int len = A.size();
    int ls = 0, hs = 0;
    for(int i = 0; i < len; i++){
        ls = ~hs & (ls ^ A[i]);
        hs = ~ls & (hs ^ A[i]);
    }
    return ls;
}