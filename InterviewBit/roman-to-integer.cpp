int Solution::romanToInt(string A) {
    map<char, int> symb;
    symb['I'] = 1, symb['V'] = 5, symb['X'] = 10, symb['L'] = 50;
    symb['C'] = 100, symb['D'] = 500,  symb['M'] = 1000;
    int len = A.size(), num = 0, crr;
    for(int i = 0; i < len; i++){
        crr = symb[A[i]];
        if(i + 1 == len){
            num += crr;
            continue;
        }
        if(symb[A[i]] < symb[A[i+1]]){
            crr = symb[A[i+1]] - symb[A[i]];
            i++;
        }
        num += crr;
    }
    return num;
}
