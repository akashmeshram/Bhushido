void removeDup(int arr[], int len){
    int crr = 0;
    for(int i = 0; i < len; i++) {
        arr[crr++] = arr[i];
        while(arr[i] == arr[i+1]) i++;
    }
    for(int i = crr; i < len; i++){
        arr[i] = 0;
    }
}