/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> graph[501];
    vector<int> vis;
    vector<int> ans;
    void init(TreeNode *root, int par=-1){
        if(!root){ return; }
        if(par!=-1){ graph[root->val].push_back(par); }
        if(root->left){
            graph[root->val].push_back(root->left->val);
            init(root->left,root->val);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            init(root->right,root->val);
        }
    }
    
    void dfs(int i, int dist){
        vis[i]=1;
        if(dist==0){ ans.push_back(i); return; }
        for(auto j:graph[i]){
            if(!vis[j]){
                dfs(j,dist-1);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        init(root);
        vis.resize(501,0);
        dfs(target->val,k);
        return ans;
    }
};