void genrateTree(TreeNode* A, queue<TreeNode* > &larr){
    if(!A) return ;
    larr.push(A);
    genrateTree(A->left, larr);
    genrateTree(A->right, larr);
} 

TreeNode* Solution::flatten(TreeNode* A) {
    queue<TreeNode* > larr;
    genrateTree(A, larr);
    TreeNode* head = larr.front();
    head->left = head->right = NULL;
    larr.pop();
    TreeNode* front = head;
    while(!larr.empty()){
        head->right = larr.front();
        larr.pop();
        head = head->right;
        head->left = head->right = NULL;
    }
    return front;
}