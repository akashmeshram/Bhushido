int Solution::reverse(int A) {
    if(A == 0) return 0;
    int flag = false;
    if(A < 0){
        A = -1 * A;
        flag = true;
    }
    long long int B = 0;
    while(A > 0){
        B *= 10;
        B += A % 10;
        if(B > INT_MAX|| B < INT_MIN) return 0;
        A /= 10;
    }
    if(flag) B = -1 * B;
    return B;
}
