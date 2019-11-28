int len;
vector<int> visit;
void search(int id, vector<int> &crr, vector<int> &A, int cnt, vector<vector<int> > &ans){
    if(len == cnt){
        ans.push_back(crr);
        return;
    }
    for(int i = 0; i < len; i++){
        if(visit[i] == 1) continue;
        visit[i] = 1;
        crr.push_back(A[i]);
        search(i, crr, A, cnt + 1, ans);
        crr.pop_back();
        visit[i] = 0;
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    len = A.size();
    visit.resize(len, 0);
    vector<vector<int> > ans;
    vector<int> crr;
    for(int i = 0; i < len; i++){
        visit[i] = 1;
        crr.push_back(A[i]);
        search(i, crr, A, 1, ans);
        crr.pop_back();
        visit[i] = 0;    
    }
    return ans;
}
