#include <bits/stdc++.h>
using namespace std;

int data[5][5] = {0};
int ds[5];

void dfs(int id) {
    for(int i = 0; i < 5; i++){
        if(data[id][i] && ds[i] == -1){
            ds[i] = ds[id] + 1;
            dfs(i);
        }
    }
}

int main()
{
    
    for(auto& row: data) for(auto& ele: row) ele = random()%2 ;
    
    for(auto& row: data) {
        for(auto& ele: row) cout << ele << " ";
        puts("");
    }
    
    memset(ds, -1, sizeof ds);
    ds[0] = 0;
    dfs(0);
    
    
    puts("distance from 0 :");
    for(auto& x: ds) cout << x << " ";

    return 0;
}
