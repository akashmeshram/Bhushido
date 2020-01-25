vector<vector<int> > Solution::solve(int A) {
    vector<vector<int> > ans;
    if(A == 0) return ans;
    ans.push_back(vector<int> (1,1));
    for(int i = 1; i < A; i++){
        vector<int> crr;
        crr.push_back(1);
        for(int j = 1; j < i; j++){
            crr.push_back(ans[i-1][j] + ans[i-1][j-1]);
        }
        crr.push_back(1);
        ans.push_back(crr);
    }
    return ans;
}
