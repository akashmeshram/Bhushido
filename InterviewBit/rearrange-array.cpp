void Solution::arrange(vector<int> &A) {
    int len = A.size(), val;
    for(int i = 0; i < len; i++){
       A.push_back(A[i]);
    }
    for(int i = 0; i < len; i++){
        A[i] = A[len + A[i]];
    }
    for(int i = 0; i < len; i++) A.pop_back();
}