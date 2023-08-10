class Solution {
public:
    vector<int> g[100005];
    vector<vector<int>> ans;
    vector<int> low, disc;
    int time=0;
    void dfs(int u, int par){
        low[u]=disc[u]=++time;
        for(auto &v:g[u]){
            if(v==par){ continue; }
            if(!disc[v]){
                dfs(v,u);
                if(disc[u]<low[v]){
                    ans.push_back({u,v});
                }
                low[u]=min(low[u],low[v]);
            }
            else{
                low[u]=min(low[u],disc[v]);
            }
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto &c:connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }
        low=disc=vector<int>(n,0);
        for(int i=0; i<n; i++){
            if(disc[i]==0){ dfs(i,i); }
        }
        return ans;
    }
};