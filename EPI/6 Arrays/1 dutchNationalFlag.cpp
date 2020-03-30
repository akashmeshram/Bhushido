void partition(int arr[], int id, int len{
    int start = 0, mid = 0, end = len-1;
    
    while(mid <= end) {
        if(arr[mid] < id) {
            swap(arr[mid], arr[start]);
            mid++;
            start++;
        } else
        if(arr[mid] > id) {
            swap(arr[mid], arr[end]);
            end--;
        } else
        if(arr[mid] == id) {
            mid++;
        }
    }
    
}