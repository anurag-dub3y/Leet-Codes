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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q){ return root; }
        TreeNode* x=lowestCommonAncestor(root->left,p,q);
        TreeNode* y=lowestCommonAncestor(root->right,p,q);
        if(!x && !y){ return nullptr; }
        if(x && y){ return root; }
        if(x){ return x; }
        else{ return y; }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        vector<TreeNode*> leaves;
        while(!bfs.empty()){
            int sz=bfs.size();
            vector<TreeNode*> tmp;
            while(sz--){
                auto t=bfs.front(); bfs.pop();
                tmp.push_back(t); 
                if(t->left){ bfs.push(t->left); }
                if(t->right){ bfs.push(t->right); }
            }
            leaves=tmp;
        }
        // for(auto &i:leaves){ cout<<i->val<<' '; } cout<<endl;
        TreeNode* lca=leaves[0];
        for(int i=1; i<leaves.size(); i++){
            lca=lowestCommonAncestor(root,lca,leaves[i]);
        }
        return lca;
    }
};