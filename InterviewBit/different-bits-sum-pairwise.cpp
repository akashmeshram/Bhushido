int Solution::cntBits(vector<int> &A) {
    int len = A.size();
    long long int ans = 0, crr;
    for(int i = 0; i < 32; i++){
        crr = 0;
        for(int j = 0; j < len; j++){
            if(A[j] & 1) crr++;
            A[j] >>= 1;
        }
        ans += crr*(len-crr)*2;
    }
    return ans%1000000007;
}