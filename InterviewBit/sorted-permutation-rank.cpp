int findrsmall(string A, int id, int len){
    int cnt = 0;
    for(int i = id + 1; i < len; i++){
        if(A[i] < A[id]) cnt++;
    }
    return cnt;
}

int fact(int k){ return (k == 1)? 1 : (fact(k-1)*k)%1000003;}

int Solution::findRank(string A) {
    int cnt = 1;
    int len = A.size(), leftc;
    for(int i = 0; i < len-1; i++){
        leftc = findrsmall(A, i, len);
        cnt += leftc*fact(len-i-1);
    }
    return cnt % 1000003 ;
}