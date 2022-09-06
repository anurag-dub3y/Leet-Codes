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
    bool hasOne(TreeNode *root){
        if(!root){ return false; }
        return root->val==1 or hasOne(root->left) or hasOne(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root or !hasOne(root)){ return nullptr; }
        TreeNode* head=new TreeNode(root->val);
        head->left=pruneTree(root->left);
        head->right=pruneTree(root->right);
        return head;
    }
};