int Solution::lca(TreeNode* A, int B, int C) {
    int t = 1, b, c;
    map<int, int> varr;
    bool fB = false, fC = false;
    queue<pair<TreeNode*, int> > st;
    pair<TreeNode*, int> crr;
    st.push(make_pair(A, t));
    while(!st.empty()){
        crr = st.front(), st.pop();
        t = crr.second;
        A = crr.first;
        if(!fB && A->val == B){fB = true; b = t;}
        if(!fC && A->val == C){fC = true; c = t;}
        varr[t] = A->val;
        if(A->left) st.push(make_pair(A->left, 2*t));
        if(A->right) st.push(make_pair(A->right, 2*t + 1));
    }
    if(!fB || !fC) return -1;
    while(b!=c){
        if(b < c) c/=2;
        else
        if(c < b) b/=2;
    }
    return varr[b];
}