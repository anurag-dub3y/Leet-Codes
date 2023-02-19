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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){ return ans; }
        queue<TreeNode*> q; q.push(root);
        int f=1;
        while(!q.empty()){
            int n=q.size(); vector<int> temp;
            for(int i=0; i<n; i++){
                auto front=q.front(); q.pop();
                temp.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(f==-1){ reverse(temp.begin(),temp.end()); }
            ans.push_back(temp);
            f*=-1;
        }
        return ans;
    }
};