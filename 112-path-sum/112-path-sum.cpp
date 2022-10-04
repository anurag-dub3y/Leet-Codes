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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL){ return false; }
        
        int x=root->val; 
        
        // If we are at the end leaf
        if(!root->left && !root->right){ return x==targetSum; }
        
        // If both children are present, either's true condition in satisfactory
        return hasPathSum(root->left,targetSum-x) or hasPathSum(root->right,targetSum-x);
    }
};