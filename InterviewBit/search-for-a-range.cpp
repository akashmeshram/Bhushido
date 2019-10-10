vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int l = 0, h = A.size()-1, aid = -1, mid;
    while(l <= h){
        mid = l + (h-l)/2;
        if(A[mid] > B) h = mid - 1;
        else if(A[mid] < B) l = mid + 1;
        else {aid = mid; break;}
    }
    if(aid == -1) return vector<int> {-1, -1};
    l = upper_bound(A.begin(), A.end(), B) - A.begin() - 1;
    h = lower_bound(A.begin(), A.end(), B) - A.begin();
    return vector<int> {h, l};
}