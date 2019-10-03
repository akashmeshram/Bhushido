int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(!A && !B) return 1;
    if(A && !B || !A && B) return 0;
    if(A->val != B->val) return 0;
    return min(isSameTree(A->right, B->right), isSameTree(A->left, B->left));
}
