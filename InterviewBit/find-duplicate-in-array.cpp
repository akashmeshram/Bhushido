int Solution::repeatedNumber(const vector<int> &A) {
    bool arr[A.size()];
    memset(arr, false, sizeof(arr));
    for(int i = 0; i < A.size(); i++){
        if(arr[A[i]]){
            return A[i];
        }
        arr[A[i]] = true;
    }
    return -1;
}
