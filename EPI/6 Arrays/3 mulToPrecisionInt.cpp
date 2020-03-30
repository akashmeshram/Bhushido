vector<int> mulVecInt(vector<int> &A, vector<int> &B) {
    vector<int> ans(A.size()+B.size(), 0);
    
    for(int i = A.size()-1; i >= 0; --i){
        for(int j = B.size()-1; j >= 0; --j){
            ans[i+j+1] += A[i]*B[j];
            ans[i+j] += ans[i+j+1]/10;
            ans[i+j+1] %= 10;
        }
    }
    
    return ans;
}