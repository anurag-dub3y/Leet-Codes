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
    vector<int> v;
    void dfs(TreeNode* root){
        if(!root){ return; }
        v.push_back(root->val);
        dfs(root->left); dfs(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        dfs(root);
        sort(v.begin(),v.end());
        for (int q : queries) {
            auto it = lower_bound(begin(v), end(v), q);
            if (it != end(v) && *it == q){ res.push_back({q, q}); }
            else{ res.push_back({it == begin(v) ? -1 : *prev(it), it == end(v) ? -1 : *it}); }
        }
        return res;
    }
};