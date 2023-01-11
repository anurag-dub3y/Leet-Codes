class Solution {
public:
    vector<int> g[100005];
    vector<int> vis;
    int dfs(int i, vector<bool>& hasApple){
        vis[i]=1;
        int time=0;
        for(auto u:g[i]){
            if(!vis[u]){
                time+=dfs(u,hasApple);
            }
        }
        if(i!=0 and (hasApple[i] or time>0)){ time+=2; }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vis.resize(n+1,0);
        for(auto e:edges){ g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
        return dfs(0,hasApple);
    }
};