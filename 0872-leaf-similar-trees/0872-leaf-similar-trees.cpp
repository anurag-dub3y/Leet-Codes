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
    void dfs(vector<int> &v, TreeNode* root){
        if(!root){ return; }
        if(!root->left and !root->right){
            v.push_back(root->val);
            cout<<root->val;
        }
        dfs(v,root->left); dfs(v,root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1){ return !root2; }
        vector<int> v1, v2;
        dfs(v1,root1); cout<<endl; dfs(v2,root2);
        return v1==v2;
    }
};