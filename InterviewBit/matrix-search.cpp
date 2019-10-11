int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int row = A.size();
    int col = A[0].size();
    int l = 0, h = row*col - 1;
    int mid, ele;
    while(l <= h){
        mid = l + (h-l)/2;
        ele = A[mid/col][mid%col];
        if(ele > B) h = mid - 1;
        else if(ele < B) l = mid + 1;
        else return 1;
    }
    return 0;
}