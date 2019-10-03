void findkth(TreeNode* A, int &ans, int B, int &track){
    if(!A) return;
    findkth(A->left, ans, B, track);
    track++;
    if(track == B){
        ans = A->val;
        return;
    }
    findkth(A->right, ans, B, track);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = 0, track = 0;
    findkth(A, ans, B, track);
    return ans;
}