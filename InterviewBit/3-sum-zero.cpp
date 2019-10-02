vector<vector<int> > Solution::threeSum(vector<int> &A) {
    int len = A.size(), temp;
    set<vector<int> > B;
    vector<vector<int> > ans;
    sort(A.begin(), A.end());
    int j, k;
    for(int i = 0; i < len-1; i++){
        j = i+1, k = len-1;
        while(j < k){
            if(A[i] + A[j] + A[k] == 0){
                if(B.find(vector<int> {A[i], A[j], A[k]}) == B.end()){
                    ans.push_back(vector<int> {A[i], A[j], A[k]});
                    B.insert(vector<int> {A[i], A[j], A[k]});
                }
                j++, k--;
            } else
            if(A[i] + A[j] + A[k] < 0) j++;
            else k--;
        }
    }
    return ans;
}