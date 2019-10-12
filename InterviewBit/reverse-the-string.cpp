string Solution::solve(string A) {
    stack<string> st;
    string crr = "";
    int len = A.size(), i = 0, cnt = 0;
    while(A[i] == ' ') i++;
    for(; i < len; i++){
        if(A[i] == ' '){
            while(A[i] == ' ') i++;
            cnt++;
            st.push(crr);
            if(i >= len) break;
            crr = "";
        }
        crr = crr + A[i];
        if(A[i+1] == '\0') {
            cnt++;
            st.push(crr);
        }
    }
    crr = "";
    while(!st.empty()){
        crr = crr + st.top();
        cnt--;
        st.pop();
        if(cnt) crr = crr + ' ';  
    }
    return crr;
}