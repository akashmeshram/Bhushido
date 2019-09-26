// UVa 124 - Following Orders
#include<bits/stdc++.h>
using namespace std;

map<char, int> cTi;
char iTc[20];
int data[20][20], m, visit[20], st[20], tp;

void dfs() {
    if(tp == m) {
        for(int j = 0; j < m; j++) {
            cout << iTc[st[j]];
        }
        puts("");
        return;
    }
    for(int i =0; i < m; i++) {
        if(!visit[i]) {
            for(int k = 0; k < m; k++) {
                if(data[i][k] && visit[k]) return;
            }
            visit[i] = 1;
            st[tp++] = i;
            dfs();
            tp--;
            visit[i] = 0;
        }
    }
}

int main() {
    string line;
    int t = 0;
    while(getline(cin, line)) {
        t++;
        if(t & 1) {
            m = 0;
            fill_n(*data, sizeof data / sizeof **data, 0);
            memset(visit, 0, sizeof(visit));
            for(int i = 0; ; i+=2) {
                iTc[m] = line[i];
                cTi[line[i]] = m++;
                if(line[i+1] == '\0') break;
            }
        } else {
            for(int i = 0; ; i+=4) {
                int x =  cTi[line[i]];
                int y =  cTi[line[i+2]];
                data[x][y] = 1;                
                if(line[i+3] == '\0') break;
            }
            tp = 0;
            dfs();
        }
    }
}
