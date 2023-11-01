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
    unordered_map<int,int> f;
    int mx=0;
    void find(TreeNode *root){
        if(!root) return;
        ++f[root->val];
        if(f[root->val]>mx){
            mx=max(mx,f[root->val]);
        }
        find(root->left);
        find(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        find(root);
        vector<int> ans;
        for(auto &[i,j]:f){
            if(j==mx){ ans.push_back(i); }
        }
        return ans;
    }
};