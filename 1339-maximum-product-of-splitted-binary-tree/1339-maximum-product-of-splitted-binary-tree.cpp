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
    long long MOD=1e9+7;
    long long totalTreeSum=0,result=0;
    int SumUnder(TreeNode* root){
        if(!root) return 0;
        long long sum=SumUnder(root->left)+SumUnder(root->right)+root->val; 
        result=max(result,sum*(totalTreeSum-sum));            
        return sum;
    }
    int maxProduct(TreeNode* root){
        totalTreeSum=SumUnder(root);
        SumUnder(root);
        return result%MOD;
    }
};