class Solution {
public:
    vector<int> vis, order;
    vector<int> g[2001];
    bool dfs(int i){
        vis[i]=1;
        order[i]=1;
        for(auto j:g[i]){
            if(!vis[j]){ if(dfs(j)){ return true; } }
            else if(order[j]==1){ return true; }
        }
        order[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& req) {
        vis.resize(n+1,0);
        order.resize(n+1,0);
        for(auto k:req){
            int u=k[0], v=k[1];
            g[u].push_back(v);
        }
        for(int i=0; i<=n; i++){
            if(!vis[i]){
                if(dfs(i)){ return false; }
            }
        }
        return true;
    }
};