#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int h, int mid) {
    int * p;
    p = new int[h-l + 1];
    int i = l;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=h) {
        if(arr[i] > arr[j]) p[k++] = arr[j++];
        else                p[k++] = arr[i++];
    }
    while(i <= mid) p[k++] = arr[i++];
    while(j <= h)   p[k++] = arr[j++];
    for(k = l; k <= h; k++) arr[k] = p[k-l];
    delete[] p;
}

void mergeSort(int arr[], int l, int h) {
    if(l >= h) return;
    int mid = l + (h - l)/2 ;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, h);
    merge(arr, l, h, mid);
}

int main()
{
    int arr[10] = {0};
    for(int& x: arr) x = rand()%20;
    for(int x: arr) cout << x << " ";

    puts("");
    
    mergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for(int x: arr) cout << x << " ";

    return 0;
}
