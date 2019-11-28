void search(int id, vector<int> &crr, vector<int> &A, vector<bool> &visit, vector<vector<int> > &ans){
    crr.push_back(A[id]);
    ans.push_back(crr);
    for(int i = id + 1; i < A.size(); i++){
        if(visit[i]) continue;
        visit[i] = true;
        search(i, crr, A, visit, ans);
        visit[i] = false;
    }
    crr.pop_back();
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    vector<int> crr;
    vector<bool> visit(A.size());
    ans.push_back(crr);
    for(int i = 0; i < A.size(); i++){
        visit[i] = true;
        search(i, crr, A, visit, ans);
        visit[i] = false;
    }
    return ans;
}
