int getProfit(int arr[], int len) {
    int m = arr[0];
    int ans = 0;
    for(int i = 0; i < len; i++) {
        ans = max(ans, arr[i] - m);
        m = min(m, arr[i]);
    }
    return ans;
}