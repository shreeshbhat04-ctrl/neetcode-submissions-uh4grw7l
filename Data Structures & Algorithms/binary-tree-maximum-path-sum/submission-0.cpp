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

    int maxPathSum(TreeNode* root) { 
        int maxi=INT_MIN;
        maxdown(root,maxi);
        return maxi;
    }
    int maxdown(TreeNode* root,int& maxi){
    if(root==NULL)return 0;
    int lefth=max(0,maxdown(root->left,maxi));
    int righth=max(0,maxdown(root->right,maxi));
    maxi=max(maxi,lefth+righth+root->val);
    return max(lefth,righth)+root->val;
}
};
