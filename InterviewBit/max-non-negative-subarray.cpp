vector<int> Solution::maxset(vector<int> &A) {
    vector<int> crr;
    vector<int> crrans;
    int ans = -1, cans = 0;
    for(auto i : A){
        if(i < 0) {
            if(ans < cans) crrans = crr, ans = cans;
            cans = 0;
            crr.clear();
        } else {
            cans += i;
            crr.push_back(i);
        }
    }
    if(ans < cans) return crr;
    else return crrans;
}
