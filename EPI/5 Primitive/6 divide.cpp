int divide(int a, int b) {
    int ans = 0;
    while(a > b){
        int t = 0;
        while(a > (b<<t++));
        a -= (b<<(t-2));
        ans += (1<<(t-2));
    }
    return  ans;
}