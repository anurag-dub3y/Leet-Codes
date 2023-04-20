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
    int widthOfBinaryTree(TreeNode* head) {
        if(!head){ return 0; }
        if(!head->left and !head->right){ return 1; }
        int ans=1;
        queue<pair<TreeNode*,int>> q;
        q.push({head,0});
        while(!q.empty()){
            int sz = q.size();
            int a = q.front().second;
            int b = q.back().second;
            ans=max(ans,b-a+1);
            for(int i=0; i<sz; i++){
                pair<TreeNode*, int> p = q.front();
                q.pop();
                int ind = p.second - a;
                if(p.first->left){ q.push({p.first->left,2LL*ind+1}); }
                if(p.first->right){ q.push({p.first->right,2LL*ind+2}); }
            }
        }
        return ans;
    }
};