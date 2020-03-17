#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main()
{   
    int data[5][5] = {0};
    for(auto& row: data) for(auto& ele: row) ele = random()%2 ;
    
    for(auto& row: data) {
        for(auto& ele: row) cout << ele << " ";
        puts("");
    }
    
    int ds[5] = {0};
    for(auto& e: ds) e = 1000;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, 0));
    ds[0] = 0;
    while(!pq.empty()){
        ii f = pq.top();
        pq.pop();
        if(f.first != ds[f.second]) continue;
        for(int i = 0; i < 5; i++){
            if(f.second == i) continue;
            if(data[f.second][i]) {
                if(ds[i] > f.first + data[f.second][i]) {
                    ds[i] = f.first + data[f.second][i];
                    pq.push(ii(ds[i], i));
                }
            }
        }
    }
    puts("----------");
    for(auto& e: ds) cout << e << " ";

    return 0;
}