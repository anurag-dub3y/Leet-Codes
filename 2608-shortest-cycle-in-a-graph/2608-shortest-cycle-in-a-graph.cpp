class Solution {
public:
    const static int MX=1010;
    vector<int> g[MX];
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        for(auto e:edges){
            g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]);
        }
        return shortest_cycle(n);
    }
    int shortest_cycle(int n){
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, (int)(1e9));
            vector<int> par(n, -1);
            dist[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int child : g[x]) {
                    if (dist[child] == (int)(1e9)) {
                        dist[child] = 1 + dist[x];
                        par[child] = x;
                        q.push(child);
                    }
                    else if (par[x] != child and par[child] != x){
                        ans = min(ans, dist[x] + dist[child] + 1);
                    }
                }
            }
        }
        if (ans == INT_MAX) return -1;
        else return ans;
    }
};