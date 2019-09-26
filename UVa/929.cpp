//929 - Number Maze
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
ii crr;
int data[1000][1000], m, n, val[1000][1000], id, x, y, crx, cry;

void digstra(){
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    val[0][0] = 0;
    pq.push(ii(0, 0));
    while(!pq.empty()){
        crr = pq.top();
        pq.pop();
        cry = crr.second / m; crx = crr.second % m;
        if(val[cry][crx] != crr.first) continue;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(fabs(i) == fabs(j)) continue;
                x = crx + j; y = cry + i;
                if(x < 0 || x >= m || y < 0 || y >= n) continue;
                if(val[y][x] > data[y][x] + crr.first) {
                    val[y][x] = data[y][x] + crr.first;
                    pq.push(ii(val[y][x], m*y + x));
                }
            }
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        memset(data, 0, sizeof(data));
        fill_n(*val, sizeof(val)/sizeof(**val), 1000);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &data[i][j]);
            }
        }
        digstra();        
        printf("%d\n", val[n-1][m-1]);
    }

    return 0;
}
