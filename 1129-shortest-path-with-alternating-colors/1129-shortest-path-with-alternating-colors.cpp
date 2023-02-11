class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> g(n);
        vector<int> ans(n,-1);
        for(auto r:redEdges){ g[r[0]].push_back({r[1],0});  }
        for(auto b:blueEdges){ g[b[0]].push_back({b[1],1}); }
        queue<vector<int>> q;
        q.push({0,0,-1});       // {edge,distance,edgeColor}
        while(!q.empty()) {
            auto x = q.front(); q.pop();
            ans[x[0]] = (ans[x[0]]!=-1)?ans[x[0]]:x[1];
            for(auto &j:g[x[0]]) {
                if(x[2]!=j.second && j.first!= -1) {
                    q.push({j.first, x[1]+1, j.second});
                    j.first=-1;
                }
            }
        }
        return ans;
    }
};