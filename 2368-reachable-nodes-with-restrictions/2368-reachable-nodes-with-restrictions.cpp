class Solution {
public:
    vector<int> g[100005];
    int dfs(int i, vector<int> &vis){
        int cnt=1;
        vis[i]=1;
        for(auto &j:g[i]){
            if(!vis[j]){ cnt+=dfs(j,vis); }
        }
        return cnt;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restr) {
        sort(begin(restr),end(restr));
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> vis(n,0);
        for(auto &i:restr){ vis[i]=1; }
        return dfs(0,vis);
    }
};