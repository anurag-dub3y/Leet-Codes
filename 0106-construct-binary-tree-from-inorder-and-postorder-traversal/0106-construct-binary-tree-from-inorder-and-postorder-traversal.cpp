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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        int postsize=postorder.size()-1;
        return function(inorder,postorder,0,inorder.size()-1,postsize);
    }
    
    // TreeNode* function(vector<int> &inorder, vector<int> &postorder, int i, int j, int &postsize){
    //     if(i>j){ return nullptr; }
    //     TreeNode* root=new TreeNode(postorder[postsize]);
    //     postsize--;
    //     int k=find(inorder.begin(),inorder.end(),root->val)-inorder.begin();
    //     root->left=function(inorder,postorder,i,k-1,postsize);
    //     root->right=function(inorder,postorder,k+1,j,postsize);
    //     return root;
    // }
    
    TreeNode* function(vector<int>& in, vector<int>& post, int inStart, int inEnd, int& postIdx) {
        if(inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(post[postIdx--]);
        int inIdx = find(begin(in), end(in), root -> val) - begin(in);
        root -> right = function(in, post, inIdx+1, inEnd, postIdx);
        root -> left  = function(in, post, inStart, inIdx-1, postIdx);
        return root;
    }
};