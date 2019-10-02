int cmp(int x, int y){
    string a = to_string(x), b = to_string(y);
    return (a + b < b + a)? 1: 0;
}

string Solution::largestNumber(const vector<int> &arr) {
    vector<int> A = arr;
    int len = A.size();
    sort(A.begin(), A.end(), cmp);
    string ans = "";
    for(int i = len - 1; i >= 0; i--){
        ans = ans + to_string(A[i]);
    }
    if(ans[0] == '0') return "0";
    return ans;
}
