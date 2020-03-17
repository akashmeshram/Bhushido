#include <bits/stdc++.h>
using namespace std;

int main()
{
    int data[5][5] = {0};
    for(auto& row: data) for(auto& ele: row) ele = random()%2 ;
    
    for(auto& row: data) {
        for(auto& ele: row) cout << ele << " ";
        puts("");
    }
    
    stack<int> dp;
    int ds[5];
    memset(ds, -1, sizeof ds);
    dp.push(0);
    ds[0] = 0;
    while(!dp.empty()) {
        int crr = dp.top();
        dp.pop();
        for(int i = 0 ; i < 5; i++) {
            if(i == crr) continue;
            
            if(data[crr][i] == 1 && ds[i] == -1) {
                dp.push(i);
                ds[i] = ds[crr] + 1;
            }
        }
    }
    puts("distance from 0 :");
    for(auto& x: ds) cout << x << " ";

    return 0;
}