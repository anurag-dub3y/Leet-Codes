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
    int maxLevelSum(TreeNode* root) {
        vector<pair<int,int>> vp;   
        queue<TreeNode*> q;
        q.push(root); int lvl=1;
        while(!q.empty()){
            int sz=q.size(), sum=0;
            for(int i=0; i<sz; i++){
                auto t=q.front(); q.pop();
                sum+=t->val;
                if(t->left){ q.push(t->left); }
                if(t->right){ q.push(t->right); }
            }
            vp.push_back({sum,lvl++});
        }
        sort(begin(vp),end(vp));
        int mxSum=vp.back().first;
        for(auto it:vp){
            if(it.first==mxSum){ return it.second;}
        }
        return vp.back().second;
    }
};