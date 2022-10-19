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
    unordered_map<string,vector<TreeNode*>> m;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> nodes;
        for(auto it:m){
            if(it.second.size()>1){
                nodes.push_back(it.second[0]);
            }
        }
        return nodes;
    }
    string dfs(TreeNode* root){
        if(!root){ return ""; }
        string s="("+dfs(root->left)+to_string(root->val)+dfs(root->right)+")";
        m[s].push_back(root);
        return s;
    }
};