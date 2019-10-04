void dfs(TreeNode* A, vector<vector<int> > &arr, int cnt, int &len) {
    if(!A) return;
    arr[cnt].push_back(A->val);
    dfs(A->left, arr, cnt + 1, len);
    dfs(A->right, arr, cnt + 1, len);
    len = max(len, cnt+1);
}

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > arr(1000);
    int cnt = 0, len = 0;
    dfs(A, arr, cnt, len);
    arr.resize(len);
    return arr;
}