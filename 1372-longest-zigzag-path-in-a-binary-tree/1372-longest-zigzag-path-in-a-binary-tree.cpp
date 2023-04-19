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
    int dfs(TreeNode* n, bool left, int depth) {
        if(!n){ return depth; }
        if(left){
            return max(dfs(n->left,!left,depth+1),dfs(n->right,left,0));
        }
        return max(dfs(n->right,!left,depth+1),dfs(n->left,left,0));
    }
    int longestZigZag(TreeNode* root) {
        return max(dfs(root, true, -1), dfs(root, false, -1));
    }
};