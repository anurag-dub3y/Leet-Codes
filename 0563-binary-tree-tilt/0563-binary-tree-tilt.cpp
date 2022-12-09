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
    int ans=0;
    int sum(TreeNode* root){ if(!root){ return 0; } return root->val+sum(root->left)+sum(root->right); }
    void dfs(TreeNode *root){
        if(!root){ return; }
        ans+=abs(sum(root->left)-sum(root->right));
        dfs(root->left); dfs(root->right);
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
};