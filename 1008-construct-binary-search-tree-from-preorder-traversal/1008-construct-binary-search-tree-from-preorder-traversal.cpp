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
    TreeNode* bstFromPreorder(vector<int>& p) {
        if(p.size()==0){ return nullptr; }
        TreeNode* root=new TreeNode(p[0]);
        int ind=p.size();
        for(int i=1; i<p.size(); i++){
            if(p[i]>p[0]){
                ind=i; break;
            }
        }
        vector<int> tmp1(p.begin()+1,p.begin()+ind);
        vector<int> tmp2(p.begin()+ind,p.end());
        root->left=bstFromPreorder(tmp1);
        root->right=bstFromPreorder(tmp2);
        return root;
    }
};