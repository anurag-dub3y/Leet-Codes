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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> vec;
        vector<vector<int>> ans;
        if(!root){ return ans; }
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int x = p.second.first, y = p.second.second;
            // x is order from left
            // y is map<int,vii>
            vec[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        for(auto mp:vec){
            vector<int> column;
            for(auto v:mp.second){
                column.insert(column.end(),v.second.begin(),v.second.end());
            }
            ans.push_back(column);
        }
        return ans;
    }
};