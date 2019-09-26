//UVa 10199 - Tourist Guide 
#include<bits/stdc++.h>
using namespace std;

typedef map<string, int> sTi;

int n, a, b, m;
string place;
int data[100][100];
sTi places;

int arti[100], low[100], vtime[100], parent[100], ti = 0, roots, ans;

void getpoints(int k) {
    vtime[k] = low[k] = ti++;
    for(int i = 0; i < m; i++) {
        if(data[k][i]) {
            if(vtime[i]) {
                parent[i] = k;
                if(k == 0) roots++;
                getpoints(i);
                if(vtime[k] <= low[i]) arti[i] = 1;
                low[k] = min(low[k], low[i]);
            } else if(parent[k] != i) {
                low[k] = min(low[k], low[i]);
            }
        }
    }

}

int main() {
    int t = 0;
    string pl, pl2;
    while(scanf("%d", &n) == 1 && n != 0) {
        t++;
        if(t & 1) {
            m = n;
            for(int i = 0; i < n; i++) {
                cin >> pl;
                places[pl] = i;
            }
        } else {
            for(int i = 0; i < n; i++) {
                cin >> pl >> pl2;
                a = places[pl], b = places[pl2];
                data[a][b] = data[b][a] = 1;
            }
            roots = -1;
            getpoints(0);
            if(roots) arti[0] = 1;
            ans = 0;
            for(int j = 0; j < m; j++) {
                if(arti[j]) ans++;
            }
            cout << ans << '\n';
        }        
    }
    return 0;   
}
