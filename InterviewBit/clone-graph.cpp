UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    UndirectedGraphNode *crr, *ncrr, *nncrr;
    unordered_set<UndirectedGraphNode* >visit;
    map<UndirectedGraphNode*, UndirectedGraphNode* > clonemap;
    
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    clonemap[node] = newNode;
    visit.insert(newNode);
    
    queue<UndirectedGraphNode* > qu, newqu;
    vector<UndirectedGraphNode* > cv;
    
    qu.push(node);
    newqu.push(newNode);
    
    int len;
    while(!qu.empty()){
        ncrr = newqu.front(), newqu.pop();
        crr = qu.front(), qu.pop();
        
        if(visit.find(crr) != visit.end()) continue;
        visit.insert(crr);
        
        cv = crr->neighbors;
        len = cv.size();
        
        for(int i = 0; i < len; i++){
            if(clonemap[cv[i]]) {
                nncrr = clonemap[cv[i]];
            } else {
                nncrr = new UndirectedGraphNode(cv[i]->label);
                clonemap[cv[i]] = nncrr;
            }
            ncrr->neighbors.push_back(nncrr);
            newqu.push(nncrr);
            qu.push(cv[i]);
        }
    }
    return newNode;
}