//341 - Non-Stop Travel
#include<bits/stdc++.h>
using namespace std;

int data[11][11];
int n, st, ed, val;
int dist[11];

typedef pair<int, int> li;

void distra(){
    li crr;
    priority_queue<li, vector<li>, greater<li> > lists; 
    lists.push(li(dist[st], st));
    while(!lists.empty()){
        crr = lists.top();
        lists.pop();
        if(crr.first != dist[crr.second]) continue;
        for(int i = 1; i <= n; i++){        
            if(data[crr.second][i] && dist[i] > crr.first + data[crr.second][i]) {
                dist[i] = crr.first + data[crr.second][i];
                lists.push(li(dist[i], i));
            }
        }
    }
}

int main() {
    while(scanf("%d\n", &n) == 1 && n != 0){
        memset(data, 0, sizeof(data[0][0])*10*10);
        fill_n(dist, sizeof(dist), 1000);
        for(int i = 1; i <= n; i++){
            scanf("%d", &st);
            while(st--){
                scanf("%d %d", &ed, &val);
                data[i][ed] = val;
            }   
        }        
        scanf("%d %d", &st, &ed);
        dist[st] = 0;
        distra();
        cout << dist[ed] << '\n';
    }
    return 0;
}
