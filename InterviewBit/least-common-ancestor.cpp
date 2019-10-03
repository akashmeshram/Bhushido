int Solution::lca(TreeNode* A, int B, int C) {
    int t = 1;
    int varr[1000000] = {0};
    map<int, int> visit;
    queue<pair<TreeNode*, int> > st;
    pair<TreeNode*, int> crr;
    st.push(make_pair(A, t));
    while(!st.empty()){
        crr = st.front(), st.pop();
        t = crr.second;
        A = crr.first;
        visit[A->val] = t;
        varr[t] = A->val;
        if(A->left) st.push(make_pair(A->left, 2*t));
        if(A->right) st.push(make_pair(A->right, 2*t + 1));
    }
    if(!visit[B] || !visit[C]) return -1;
    int b = visit[B], c = visit[C];
    while(b!=c){
        if(b < c) c/=2;
        else
        if(c < b) b/=2;
    }
    return varr[b];
}