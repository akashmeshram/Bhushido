#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int l, int h) {
    if(l >= h) return ;
    int id = min_element(arr+l, arr+h) - arr;
    swap(arr[l], arr[id]);
    selectionSort(arr, l+1, h);
}


int main()
{
    int arr[10] = {0};
    for(int& x: arr) x = rand()%20;
    for(int x: arr) cout << x << " ";
    puts("");
    selectionSort(arr, 0, sizeof(arr) / sizeof(int) );
    for(int x: arr) cout << x << " ";

    return 0;
}