void dfs(int id, vector<vector<int> > &graph, unordered_set<int> &visit, vector<int> &A, int level){
    if(visit.find(id) != visit.end()) return;
    int len = graph[id].size();
    visit.insert(id);
    for(int i = 0; i < len; i++){
        dfs(graph[id][i], graph, visit, A, level + 1);
    }
    A[id] = level;
}

int Solution::solve(vector<int> &A) {
    unordered_set<int> visit;
    int len = A.size();
    vector<vector<int> > graph(len);
    int root;
    for(int i = 0; i < len; i++){
        if(A[i] == -1) {
            root = i;
            continue;
        }
        graph[A[i]].push_back(i);
        graph[i].push_back(A[i]);
    }
    
    int level = 0, crrl = 0;
    dfs(root, graph, visit, A, 0);
    for(int i = 0; i < len; i++){
        if(A[i] > level) {
            root = i;
            level = A[i];
        }
    }
    visit.erase(visit.begin(), visit.end());
    dfs(root, graph, visit, A, 0);
    
    return *max_element(A.begin(), A.end());
}