bool ifpossible(vector<int> &A, int crrmin, int B){
    int crrsum = 0;
    int numstd = 1;
    for(int i =0; i < A.size(); i++){
        if(A[i] > crrmin) return false;
        if(crrsum + A[i] > crrmin){
            numstd++;
            crrsum = A[i];
        } else {
            crrsum += A[i];
        }
        
        if(numstd > B) return false;
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int sum = 0;
    if(A.size() < B) return -1;
    sort(A.begin(), A.end());
    for(auto x : A) sum += x;
    int low = 0, high = sum;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high-low)/2 ;
        if(ifpossible(A, mid, B)){
            high = mid - 1;
            ans = min(ans, mid);
        } else {
            low = mid + 1;
        }
    }
    return ans;
}