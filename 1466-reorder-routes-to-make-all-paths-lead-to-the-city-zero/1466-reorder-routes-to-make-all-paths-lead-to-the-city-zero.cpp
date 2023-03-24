class Solution {
public:
    vector<vector<int>> g;
    set<pair<int,int>> pairs;
    void dfs(int root, vector<int>& vis, int &ans){
        vis[root]=1;
        for(auto j:g[root]){
            if(!vis[j]){
                // cout<<root<<' '<<j<<'\n';
                if(pairs.count({root,j})){ ans++; }
                dfs(j,vis,ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        g.resize(n);
        for(auto c:connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
            pairs.insert({c[0],c[1]});
        }
        vector<int> vis(n,0);
        int ans=0;
        dfs(0,vis,ans);
        return ans;
    }
};