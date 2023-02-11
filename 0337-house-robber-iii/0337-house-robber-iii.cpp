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
    unordered_map<TreeNode*,int> mp;
    int find(TreeNode *root){
        if(!root){ return 0; }
        if(mp.find(root)!=mp.end()){ return mp[root]; }
        int v1=root->val;
        if(root->left){
            v1+=find(root->left->left)+find(root->left->right);
        }
        if(root->right){
            v1+=find(root->right->left)+find(root->right->right);
        }
        int v2=find(root->left)+find(root->right);
        return mp[root]=max(v1,v2);
    }
    int rob(TreeNode* root) {
        return find(root);
    }
};