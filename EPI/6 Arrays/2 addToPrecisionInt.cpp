void incVecInt(vector<int> &A, int inc){
    A.back() += inc;
    for(int i = A.size()-1; i > 0 && A[i]>=10; i--){
        A[i-1] += A[i]/10;
        A[i] %= 10;
    }
    while(A[0] > 10) {
        A.insert(A.begin(), A[0]/10);
        A[1] %= 10;
    }
}