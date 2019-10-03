int Dfs(TreeNode* Tr){
     int a, b;
     if(Tr->left == NULL && Tr->right == NULL) return 1;
     a = (Tr->left != NULL)? Dfs(Tr->left):0;
     b = (Tr->right != NULL)? Dfs(Tr->right):0;
     return max(a, b) + 1;
 }
 
int Solution::maxDepth(TreeNode* A) {
    return Dfs(A);
}