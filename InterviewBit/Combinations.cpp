void search(int id, int A, int B, vector<int> &crr, vector<vector<int> > &ans){
    if(B == 0) ans.push_back(crr);
    for(int i = id + 1; i <= A; i++){
        crr.push_back(i);
        search(i, A, B-1, crr, ans);
        crr.pop_back();
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> crr;
    vector<vector<int> > ans;
    for(int i = 1; i <= A; i++){
        crr.push_back(i);
        search(i, A, B-1, crr, ans);
        crr.pop_back();
    }
    return ans;
}
