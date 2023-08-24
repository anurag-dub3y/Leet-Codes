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
    vector<int> vals;
    void dfs(TreeNode* root){
        if(!root){ return; }
        dfs(root->left); vals.push_back(root->val); dfs(root->right);
    }
    TreeNode *makeRoot(int i, int j){
        if(i>j){ return nullptr; }
        int mid=(i+j)/2;
        TreeNode *root=new TreeNode(vals[mid]);
        if(i==j){ return root; }
        root->left=makeRoot(i,mid-1);
        root->right=makeRoot(mid+1,j);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return makeRoot(0,(int)vals.size()-1);
    }
};