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
    map<int,vector<int>> graph;
    void init(TreeNode* root, int prev=-1){
        if(!root){ return; }
        if(prev!=-1){ 
            graph[root->val].push_back(prev);
        }
        if(root->left){
            graph[root->val].push_back(root->left->val);
            init(root->left,root->val);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            init(root->right,root->val);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        init(root);
        queue<int> q;
        int ans=0;
        map<int,int> vis;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            ans++;
            int sz=q.size();
            while(sz--){
                int x=q.front(); q.pop();
                for(auto j:graph[x]){
                    if(!vis.count(j)){
                        q.push(j); vis[j]=1;
                    }
                }
            }
        }
        return ans-1;
    }
};











