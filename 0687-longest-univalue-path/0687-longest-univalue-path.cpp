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
    int longestUnivaluePath(TreeNode* root) {
        if(!root){ return 0; }
        int len=0;
        dfs(root,len);
        return len;
    }
    int dfs(TreeNode* root, int& len){
        int l=root->left? dfs(root->left, len) : 0;
        int r=root->right? dfs(root->right, len) : 0;
        l=(root->left && root->left->val==root->val) ? l+1 : 0;
        r=(root->right && root->right->val==root->val) ? r+1 : 0;
        len=max(len,l+r);
        return max(l,r);
    }
};