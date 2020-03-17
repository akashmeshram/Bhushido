#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int l, int h) {
    if(l >= h) return;
    int p = arr[h];
    int i = l;
    int j = h-1;
    for(int j = l; j < h; j++){
        if(arr[j] < p) swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[h]);
    quickSort(arr, l, i-1);
    quickSort(arr, i+1, h);
}


int main()
{
    int arr[10] = {0};
    for(int& x: arr) x = rand()%20;
    for(int x: arr) cout << x << " ";

    puts("");
    
    quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for(int x: arr) cout << x << " ";

    return 0;
}
