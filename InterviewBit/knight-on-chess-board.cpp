int Solution::knight(int A, int B, int C, int D, int E, int F) {
    if(C == E && D == F) return 0;
    if(C <= 0 || D <= 0 || C > A || D > B) return -1;
    if(E <= 0 || F <= 0 || E > A || F > B) return -1;
    
    int move[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {-2, -1}, 
                        {-1, -2}, {1, -2}, {2, -1}};
    int board[A][B];
    memset(board, -1, sizeof board);
    queue<pair<int, int> > qu;
    int x, y;
    pair<int, int> crr;
    qu.push(make_pair(C-1, D-1));
    board[C-1][D-1] = 0;
    while(!qu.empty()){
        crr = qu.front(), qu.pop();
        for(int i = 0; i < 8; i++){
            x = crr.first + move[i][0], y = crr.second + move[i][1];
            if(x < 0 || x >= A || y < 0 || y >= B) continue;
            if(board[x][y] == -1){
                board[x][y] = board[crr.first][crr.second] + 1;
                qu.push(make_pair(x, y));
            }
            if(x == E-1 && y == F-1) return board[x][y];
        }
    }
    return -1;
}