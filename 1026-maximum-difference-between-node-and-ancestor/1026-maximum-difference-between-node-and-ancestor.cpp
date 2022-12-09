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
    int minVal(TreeNode* root){
        if(!root){ return 100005; }
        return min({root->val,minVal(root->left),minVal(root->right)});
    }
    int maxVal(TreeNode* root){
        if(!root){ return -1; }
        return max({root->val,maxVal(root->left),maxVal(root->right)});
    }
    void dfs(TreeNode *root){
        if(!root){ return; }
        int mn=minVal(root), mx=maxVal(root);
        int val=max(abs(root->val-mn),abs(root->val-mx));
        ans=max(ans,val);
        dfs(root->left); dfs(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};