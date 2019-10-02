vector<int> Solution::nextPermutation(vector<int> &A) {
    int len = A.size();
    int i = len - 1;
    while(A[i] <= A[i-1] && i != 0) i--;
    if(i == 0){
        reverse(A.begin(), A.end());
        return A;
    }
    int j = len - 1;
    while(A[j] <= A[i-1]) j--;
    swap(A[j], A[i-1]);
    reverse(A.begin() + i, A.end());
    return A;
}
