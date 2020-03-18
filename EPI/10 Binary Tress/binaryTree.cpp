#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* right = NULL;
        TreeNode* left = NULL;
        TreeNode(int v) {
            val = v;
        }
};
        

int main()
{   
    TreeNode* p = new TreeNode(5);
    TreeNode* l = new TreeNode(10);
    p->left = l;
    cout << p->left->val;

    return 0;
}