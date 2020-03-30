#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[15] = {0};
    
    for(int& x : arr) x = random()%10;
    for(int& x : arr) cout << x << " ";
    puts("");
    int e = 0, o = sizeof(arr) / sizeof(int) - 1;
    
    while(e < o){
        if(arr[e] & 1) {
            swap(arr[e], arr[o]);
            o--;
        } else {
            e++;
        }
    }
    for(int& x : arr) cout << x << " ";
    
    return 0;
}