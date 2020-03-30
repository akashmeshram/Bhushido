bool canReachEnd(vector<int> arr) {
    int curr = 0, last = arr.size()-1;
    
    for(int i = 0; curr >= i && curr < last; i++) {
        curr = max(curr, i + arr[i]);
    }
    
    return curr >= last;
}