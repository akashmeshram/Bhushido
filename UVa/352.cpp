//352 - The Seasonal War
#include<bits/stdc++.h>
using namespace std;

int img[25][25];
int n;
int cnt;

void dfs(int a, int b) {
    int sx = -1, sy = -1, ex = 1, ey = 1;
    if(a == 0) sx = 0;
    if(b == 0) sy = 0;
    if(a == n-1) ex = 0;
    if(b == n-1) ey = 0;
    for(int i = a + sx; i <= a + ex; i++) {
        for(int j = b + sy; j <= b + ey; j++) {
            if(img[i][j]) {
                img[i][j] = 0;
                dfs(i, j);
            }
        }
    }
}

int main() {
    char line[26];
    while(scanf("%d", &n) == 1) {
        cin.ignore();
        cnt = 0;
        memset(img, 0, sizeof(img[0][0])*25*25);
        for(int i = 0; i < n; i++) {
            gets(line);
            for(int j = 0; j < n; j++) {
                img[i][j] = line[j] - '0';
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img[i][j]) {
                    cnt++;
                    img[i][j] = 0;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}
