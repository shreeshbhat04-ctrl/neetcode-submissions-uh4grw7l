/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
   int hei(TreeNode* root,int& di){
    if(root==NULL)return 0;
    int lh=hei(root->left,di);
    int rh=hei(root->right,di);
    di=max(di,lh+rh);
    return max(lh,rh)+1;
   }
    int diameterOfBinaryTree(TreeNode* root) {
        int di=0;
        hei(root,di);
        return di;
    }
};
