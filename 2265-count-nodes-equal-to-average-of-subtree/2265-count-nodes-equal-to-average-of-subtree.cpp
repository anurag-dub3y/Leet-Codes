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
    pair<int,int> check(TreeNode *root){
        if(!root){ return {0,0}; }
        auto p1=check(root->left), p2=check(root->right);
        int sum=p1.first+p2.first+root->val, cnt=1+p2.second+p1.second;
        if(sum/cnt==root->val){ ans++; }
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        check(root);
        return ans;
    }
};