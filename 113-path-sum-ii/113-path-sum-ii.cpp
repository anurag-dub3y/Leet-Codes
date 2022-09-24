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
    vector<vector<int>> ans;
    void DFS(TreeNode *root, vector<int>& curr, int currSum, int target){
        if(!root){ return; }
        currSum+=root->val;
        curr.push_back(root->val);
        vector<int> r=curr;
        if(!root->left && !root->right && currSum==target){
            ans.push_back(curr);
        }
        if(root->left){
            DFS(root->left,curr,currSum,target);
        }
        if(root->right){
            DFS(root->right,r,currSum,target);
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        DFS(root,curr,0,targetSum);
        return ans;
    }
};