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
    unordered_map<long, int> map;
    int count = 0;
    
    void DFS(TreeNode* root, int target, long sum){
        if(!root) return;
        sum+=root->val; 
        if(sum==target){ count++; }
        if(map.find(sum-target)!=map.end()){ count += map[sum - target]; }
        map[sum]++;
        DFS(root->left, target, sum);
        DFS(root->right, target, sum);
        map[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        DFS(root, targetSum, 0);
        return count;
    }
};