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
    map<int,int> heightOfSubtree;
    int dfs(TreeNode* root){
        if(!root){ return 0; }
        return heightOfSubtree[root->val]=1+max(dfs(root->left),dfs(root->right));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int height=dfs(root);
        vector<int> ans(heightOfSubtree.size()+1);
        queue<TreeNode*> bfs;
        bfs.push(root);
        while(!bfs.empty()){
            int sz=bfs.size();
            vector<pair<int,int>> temp;
            while(sz--){
                auto f=bfs.front(); bfs.pop();
                temp.push_back({heightOfSubtree[f->val],f->val});
                if(f->left){ bfs.push(f->left); }
                if(f->right){ bfs.push(f->right); }
            }
            sort(rbegin(temp),rend(temp));
            // for(auto it:temp){
            //     cout<<it.first<<' '<<it.second<<"  ";
            // }
            // cout<<endl;
            if(temp.size()==1){ ans[temp[0].second]=height-temp[0].first; }
            else{
                for(int i=0; i<temp.size(); i++){
                    if(i==0){
                        ans[temp[i].second]=height-(temp[i].first-temp[i+1].first);
                    }
                    else{
                        ans[temp[i].second]=height;
                    }
                }
            }
        }
        vector<int> res(queries.size());
        for(int i=0; i<queries.size(); i++){
            res[i]=ans[queries[i]]-1;
        }
        return res;
    }
};