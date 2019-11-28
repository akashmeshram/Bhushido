int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int len = A.size();
    if(len == 1) return 0;
    int gas, cost, i, j;
    for(i = 0; i < len; i++){
        gas = A[i], cost = B[i];
        if((gas - B[i]) < 0) continue;
        gas = gas - B[i];
        j = (i + 1) % len;
        while(j != i){
            gas += A[j];
            if(gas - B[j] < 0) break;
            gas -= B[j];
            j = (j + 1) % len;
        }
        if(j == i) return i;
    }
    return -1;
}