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
    bool isSymmetric(TreeNode* root) {
        if(!root){ return true; }
        return test(root->left,root->right);
    }
    bool test(TreeNode* ll, TreeNode* rr){
        if(ll==NULL && rr==NULL){ return true; }
        else if (ll==NULL || rr==NULL){ return false; }
        else if(ll->val!=rr->val){ return false; }
        return test(ll->left,rr->right) && test(ll->right,rr->left);
    }
};