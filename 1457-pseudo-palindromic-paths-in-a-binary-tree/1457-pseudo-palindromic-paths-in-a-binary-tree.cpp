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
    unordered_map<int,int> s;
    void DFS(TreeNode* root){
        if(!root){ return; }
        s[root->val]++;
        if(!root->right && !root->left){
            int num=0;
            for(auto it:s){ num+=(it.second%2); }
            ans+=num<=1;
        }
        DFS(root->left);
        DFS(root->right);
        s[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        DFS(root);
        return ans;
    }
};