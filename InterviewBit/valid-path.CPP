void dfs(vector<vector<bool> > &grid, int x, int y, int A, int B, bool &found){
    if(found) return;
    if(x == A && y == B){
        found = true;
        return;
    }
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(i == j) continue;
            if(x + i < 0 || x + i > A || y + j < 0 || y + j > B) continue;
            if(grid[x + i][y + j]){
                grid[x + i][y + j] = false;
                dfs(grid, x + i, y + j, A, B, found);
            }
        }
    }
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<bool> > grid(A+1, vector<bool> (B+1, true));
    for(int c = 0; c < C; c++){
        for(int x = E[c] - D; x <= E[c] + D; x++){
            if(x < 0 || x > A) continue;
            for(int y = F[c] - D; y <= F[c] + D; y++){
                if(y < 0 || y > B) continue;
                if(sqrt(pow(x - E[c], 2) + pow(y - F[c], 2)) <= D){
                    grid[x][y] = false;
                }
            }
        }
    }
    bool found = false;
    if(grid[A][B] && grid[0][0]){
        dfs(grid, 0, 0, A, B, found);
    }
    if(found){
        return "YES";
    } else {
        return "NO";
    }
}