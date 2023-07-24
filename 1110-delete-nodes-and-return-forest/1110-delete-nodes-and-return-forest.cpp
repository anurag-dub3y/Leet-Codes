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
    vector<TreeNode*> ans;
    void dfs(TreeNode* root, TreeNode* parent, bool isLeft, set<int>& del){
        if(!root){ return; }
        if(del.count(root->val)){
            if(parent){
                if(isLeft){ parent->left=nullptr; }
                else{ parent->right=nullptr; }
            }
            // if(root->left){ ans.push_back(root->left); }
            // if(root->right){ ans.push_back(root->right); }
            dfs(root->left,nullptr,true,del);
            dfs(root->right,nullptr,false,del);
        }
        else{
            if(!parent){ ans.push_back(root); }
            dfs(root->left,root,true,del);
            dfs(root->right,root,false,del);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> del(begin(to_delete),end(to_delete));
        dfs(root,nullptr,true,del);
        return ans;
    }
};