class Solution {
public:
    vector<int> g[101];
    double dfs(int i, vector<int>& vis, int t, int target){
        if(i != 1 && g[i].size() == 1 || t == 0) {
            return i == target;
        }
        vis[i]=1;
        double sum=0.0;
        for(auto u:g[i]){
            if(!vis[u]){ sum+=dfs(u,vis,t-1,target); }
        }
        return sum/(g[i].size()-(i!=1));
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(target==1 and edges.size()==0){ return 1.0; }
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> vis(n+1,0);
        return dfs(1,vis,t,target);
    }
};