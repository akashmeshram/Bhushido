int Solution::findMedian(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    int low = INT_MAX, high = INT_MIN;
    for(int i = 0; i < r; i++){
        if(A[i][0] < low) low = A[i][0];
        if(A[i][c-1] > high) high = A[i][c-1];
    }
    int halfsize = (r*c + 1)/2;
    while(low < high){
        int mid = low + (high-low)/2;
        int cnt = 0;
        for(int i = 0; i < r; i++){
            cnt += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if(cnt < halfsize) low = mid+1;
        else high = mid;
    }
    return low;
}