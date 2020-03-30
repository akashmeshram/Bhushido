void nextPrem(int arr[], int len) {
    int i = len - 1;
    int j = len - 1;
    while(i > 0 && arr[i-1] > arr[i]) i--;
    if(i == 0) return;
    while(arr[i-1] > arr[j]) j--;
    swap(arr[i-1], arr[j]);
    reverse(arr + i, arr + len);
}