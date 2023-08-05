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
    vector<TreeNode*> find(int start, int end) {
        vector<TreeNode*> ans;
        if(start > end){ return {NULL}; }
        if(start == end){ return {new TreeNode(start)}; }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = find(start, i-1), right = find(i+1, end);
            for (auto l : left){
                for (auto r : right){
                    ans.push_back(new TreeNode(i, l, r));
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans = find(1, n);
        return ans;
    }
};