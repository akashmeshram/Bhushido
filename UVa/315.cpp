// UVa 315 - Network 
#include<bits/stdc++.h>
using namespace std;

int data[100][100], n, cnt;
int dTime[100], low[100], arti[100], parent[100];
int t, rchild;

void findpoint(int crr) {
    low[crr] = t;  
    dTime[crr] = t++;
    for(int i = 1; i <= n; i++) {
        if(data[crr][i]) {
            if(dTime[i] == -1) {
                if(crr == 1)  rchild++;
                parent[i] = crr;
                findpoint(i);
                if(dTime[crr] <= low[i]) arti[crr] = 1;
                low[crr] = min(low[crr], low[i]);
            } else if(i != parent[crr]){
                low[crr] = min(low[crr], low[i]);
            }
        }
    }    
}

int main() {
    char c;
    int m, p;
        
    while(scanf("%d", &n) == 1 && n) {
        memset(data, 0, sizeof(data[0][0])*100*100);
        memset(dTime, -1, sizeof(dTime)); 
        memset(low, -1, sizeof(low)); 
        memset(arti, 0, sizeof(low)); 
        while(scanf("%d", &m) == 1 && m) {
            while(scanf("%d%c", &p, &c) == 2) {
                data[m][p] = data[p][m] = 1;            
                if(c == '\n') break;
            }
        }
        cnt = 0;
        t = 0;
        rchild = 0;
        findpoint(1);
        arti[1] = rchild > 1 ? 1:0;
        for(int i = 1; i <= n; i++) {
            if(arti[i]) cnt++;
        } 
        printf("%d\n", cnt);      
    }

    return 0;
}
