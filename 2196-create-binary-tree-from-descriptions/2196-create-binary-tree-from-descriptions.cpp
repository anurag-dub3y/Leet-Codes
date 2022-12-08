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
    map<int,TreeNode*> m;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> isChild;
        for(auto d:descriptions){
            isChild.insert(d[1]);
            if(m.find(d[0])==m.end()){ m[d[0]]=new TreeNode(d[0]); }
            if(m.find(d[1])==m.end()){ m[d[1]]=new TreeNode(d[1]); }
            if(d[2]){ m[d[0]]->left=m[d[1]]; }
            else{ m[d[0]]->right=m[d[1]]; }
        }
        for(auto it:m){
            int x=it.first;
            if(isChild.find(x)==isChild.end()){ return m[x]; }
        }
        return {};
    }
};