string Solution::addBinary(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    if(A.size() < B.size()) swap(A, B);
    int la = A.size();
    int lb = B.size();
    string ans = "";
    int res, rem = 0;
    for(int i = 0; i < lb; i++){
        res = (A[i]-'0') + (B[i]-'0') + rem;
        rem = res/2;
        ans += to_string(res % 2);
    }
    for(int i = lb; i < la; i++){
        res = (A[i]-'0') + rem;
        rem = res/2;
        ans += to_string(res % 2);
    }
    if(rem == 1) ans += "1";
    reverse(ans.begin(), ans.end());
    return ans;
}
