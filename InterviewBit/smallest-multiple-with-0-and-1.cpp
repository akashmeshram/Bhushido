string Solution::multiple(int A) {
    if(A == 1 || A == 0) return to_string(A);
    int visit[A], edge[A];
    char val[A];
    memset(visit, -1, sizeof visit);
    queue<int> qu;
    qu.push(1);
    visit[1] = 0;
    edge[1] = -1;
    val[1] = '1';
    int r, l, crr;
    while(!qu.empty()){
        crr = qu.front(), qu.pop();
        if(crr == 0){
            string ans = "";
            int pos = crr; 
            while(pos != -1){
                ans += val[pos];
                pos = edge[pos];
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        l = (crr*10) % A;
        r = (l + 1) % A;
        if(visit[l] == -1){
            visit[l] = 0;
            edge[l] = crr;
            qu.push(l);
            val[l] = '0';
        }
        if(visit[r] == -1){
            visit[r] = 0;
            edge[r] = crr;
            qu.push(r);
            val[r] = '1';
        }
    }
}