int Solution::atoi(const string A) {
    int len = A.size(), i = 0;
    while(A[i] == ' ') i++; 
    long ans = 0;
    bool posi = true;
    if(A[0] == '+') i++;
    if(A[0] == '-') {i++; posi = false;}
    for(; i < len; i++){
        if(ans > INT_MAX && posi) return INT_MAX;
        if(ans > INT_MAX) return INT_MIN;
        if(A[i] - '0' < 0 || A[i] - '0' > 9 ) break;
        ans = ans*10 + (A[i] - '0');
    }
    if(!posi) ans *= -1;
    return ans;
}