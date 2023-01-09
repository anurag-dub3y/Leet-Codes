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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){ return ans; }
        stack<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *x=q.top();
            q.pop();
            ans.push_back(x->val);
            if(x->right){ q.push(x->right); }
            if(x->left){ q.push(x->left); }
        }
        return ans;
    }
};