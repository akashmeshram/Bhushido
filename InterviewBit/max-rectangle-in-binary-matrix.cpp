int Solution::maximalRectangle(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), ans, crr;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            A[i][j] = (A[i][j])? 1 : -9999; 
            if(i != 0) A[i][j] += A[i-1][j];
            if(j != 0) A[i][j] += A[i][j-1];
            if(i != 0 && j != 0) A[i][j] -= A[i-1][j-1];
        }
    }
    for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++){
        for(int k = i; k < n; k++){ for(int l = j; l < m; l++){
            crr = A[k][l];
            if(i != 0) crr -= A[i-1][l];
            if(j != 0) crr -= A[k][j-1];
            if(i != 0 && j != 0) crr += A[i-1][j-1];
            ans = max(ans, crr);            
        }}            
    }}
    return ans;
}
