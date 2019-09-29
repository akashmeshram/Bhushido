vector<int> Solution::plusOne(vector<int> &A) {
    int len = A.size();
    bool flag = false;
    reverse(A.begin(), A.end());
    int i = 0;
    for(i = 0; i < len; i++){
        A[i] += 1;
        if(A[i]/10 == 1){
            A[i] %= 10;
        } else {
            flag = true;
            break;
        }
    }
    if(!flag){
        A.push_back(1);
    }
    reverse(A.begin(), A.end());
    while(A[0] == 0) A.erase(A.begin());
    return A;
}