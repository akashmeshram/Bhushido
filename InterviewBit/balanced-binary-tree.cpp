int checkBalanced(TreeNode* B){
    if(!B) return 1;
    int a = checkBalanced(B->left);
    int b = checkBalanced(B->right);
    return ((abs(a-b)==1 || a==b) && a != 0 && b != 0)? max(a, b)+1 : 0;
}
 
int Solution::isBalanced(TreeNode* A) {
    if(!A->left && !A->right) return 1;
    int a = checkBalanced(A->left);
    int b = checkBalanced(A->right);
    return ((abs(a-b) == 1  || a==b) && a != 0 && b != 0)? 1 : 0;
}