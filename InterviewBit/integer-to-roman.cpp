string Solution::intToRoman(int A) {
    map<int, char> itc;
    string ans = "";
    itc[1] = 'I', itc[5] = 'V', itc[10] = 'X', itc[50] = 'L', 
    itc[100] = 'C', itc[500] = 'D', itc[1000] = 'M';
    int idx[] = {1, 5, 10, 50, 100, 500, 1000}, crr;
    int rdx[] = {0, 1,  1, 10,  10, 100,  100};
    while(A){
        for(int i = 0; i < 7; i++){
            if(A - idx[i] < 0) {
                if(A + rdx[i] >= idx[i]){
                    ans += itc[rdx[i]];
                    ans += itc[idx[i]];
                    A = A - idx[i] + rdx[i];
                    i = 0;
                } else {
                    break;
                }
            }
            if(A == 0) break;
            crr = idx[i];
        }
        if(A == 0) break;
        A = A - crr;
        ans += itc[crr];
    }
    return ans;
}