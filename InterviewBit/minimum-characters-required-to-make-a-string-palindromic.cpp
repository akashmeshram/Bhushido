bool checkPalindrom(string A, int len){
    int i = 0, j = len - 1;
    while(i <= j){
        if(A[i] != A[j]) return false;
        i++, j--;
    }
    return true;
}

int Solution::solve(string A) {
    int len = A.size(), crr = 0;
    for(int i = 1; i <= len; i++){
        if(checkPalindrom(A, i)){
            crr = i;
        }
    }
    return len - crr;
}