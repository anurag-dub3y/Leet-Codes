class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), mx = -1;
        vector<bool> visited(n,false);
        vector<int> dist(n,-1);
        
        function<void(int, int)> dfs = [&](int node, int curlen) {
            if(!visited[node]) {
                visited[node] = true;
                dist[node] = curlen;
                if(edges[node] != -1){ dfs(edges[node], curlen+1); }
                dist[node] = -1;
            }
            else {
                if(dist[node] != -1){
                    mx=max(mx,curlen-dist[node]);
                }
            }
        };
        
        for(int i=0; i<n; ++i) {
            if(visited[i]){ continue; }
            dfs(i,0);
        }
        return mx;
    }
};