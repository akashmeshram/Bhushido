double Solution::findMedianSortedArrays(const vector<int> &C, const vector<int> &D) {
    int c = C.size();
    int d = D.size();
    if(c < d) return findMedianSortedArrays(D, C);
    int l = 0, h = 2*d, mid1, mid2;
    double l1, l2, r1, r2;
    while(l <= h){
        mid2 = l + (h-l)/2;
        mid1 = c+d - mid2;
        l1 = (mid1 == 0)? INT_MIN: C[(mid1-1)/2];
        l2 = (mid2 == 0)? INT_MIN: D[(mid2-1)/2];
        r1 = (mid1 == 2*c)? INT_MAX: C[mid1/2];
        r2 = (mid2 == 2*d)? INT_MAX: D[mid2/2];
        if(l1 > r2) l = mid2 + 1;
        else if(l2 > r1) h = mid2 - 1;
        else return (max(l1, l2) + min(r1, r2))/2;
    }
}