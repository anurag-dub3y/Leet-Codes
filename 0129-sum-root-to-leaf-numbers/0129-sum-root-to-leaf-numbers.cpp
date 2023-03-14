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
    int DFS(TreeNode* root, int curr){
        if(!root){ return 0; }
        curr=curr*10 + root->val;                 // append current node's digit
        if(!root->left && !root->right){ return curr; }
        return DFS(root->left, curr) + DFS(root->right, curr);  
    }
    int sumNumbers(TreeNode* root) {
        return DFS(root,0);
    }
};