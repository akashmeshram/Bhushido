int findMax(vector<int> &A, int l, int h){
    int mx = A[l], id = l;
    for(int i = l+1; i <= h; i++) {
        if(mx < A[i]){
            mx = A[i];
            id = i;
        }
    }
    return id;
}

TreeNode* makeCart(vector<int> &A, int low, int high) {
    if(low > high) return NULL;
    int id = findMax(A, low, high);
    TreeNode* node = new TreeNode(A[id]);
    node->left = makeCart(A, low, id-1);
    node->right = makeCart(A, id+1, high);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    return makeCart(A, 0, A.size()-1);
}
