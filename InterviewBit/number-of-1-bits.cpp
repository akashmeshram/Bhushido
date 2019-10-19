int Solution::numSetBits(unsigned int A) {
    int cnt = 0;
    for(int i = 0; i < 32; i++){
        if(A & 1) cnt++;
        A >>= 1;
    }
    return cnt;
}