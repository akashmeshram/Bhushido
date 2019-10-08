int Solution::solve(string A, string B, vector<string> &C) {
    C.push_back(A);
    C.push_back(B);
    int len = A.size(), cnt;
    int twds = C.size();
    vector<vector<int> > graph(twds);
    for(int i = 0; i < twds - 1; i++){
        for(int j = 0; j < twds; j++){
            cnt = 0;
            for(int k = 0; k < len; k++){
                if(C[i][k] != C[j][k]) cnt++;
                if(cnt > 1) break;
            }
            if(cnt == 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    int dist[twds];
    memset(dist, -1, sizeof dist);
    queue<int> qu;
    qu.push(twds-2);
    dist[twds-2] = 1;
    int k;
    while(!qu.empty()){
        cnt = qu.front(), qu.pop();
        len = graph[cnt].size();
        for(int i = 0; i < len; i++){
            k = graph[cnt][i];
            if(dist[k] == -1){
                dist[k] = dist[cnt] + 1;
                qu.push(k);
            }
        }
    }
    return dist[twds-1];
}