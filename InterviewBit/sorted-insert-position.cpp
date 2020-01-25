int bsearch(vector<int> &A, int B, int low, int high){
    if(low > high) return low;
    int mid = low + (high - low)/2;
    if(A[mid] > B) return bsearch(A, B, low, mid-1);
    else
    if(A[mid] < B) return bsearch(A, B, mid+1, high);
    return mid;
}

int Solution::searchInsert(vector<int> &A, int B) {
   return bsearch(A, B, 0, A.size()-1);
}