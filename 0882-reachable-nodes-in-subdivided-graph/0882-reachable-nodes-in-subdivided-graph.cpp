class Solution {
public:
    vector<pair<int,int>> g[3001];
    int n;
    vector<int> djikstra(int src){
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
		vector<bool> vis(n + 1, false);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.emplace(0, src);
        int u, v, w;
        while (!pq.empty()) {
            u = pq.top().second; pq.pop();
			if (vis[u]) continue;
			vis[u] = true;
            for (auto& to : g[u]) {
                v = to.first, w = to.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        this->n=n;
        for(auto &e:edges){
            g[e[0]].push_back({e[1],1+e[2]});
            g[e[1]].push_back({e[0],1+e[2]});
        }
        vector<int> dist=djikstra(0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(dist[i]<=maxMoves){ ans++; }
        }
        for(auto &e:edges){
            // cout<<ans<<endl;
            int u=e[0], v=e[1], cnt=e[2];
            // cout<<u<<' '<<v<<' '<<cnt<<endl;
            int left=max(0,maxMoves-dist[u]);
            int right=max(0,maxMoves-dist[v]);
            ans+=min(left+right,cnt);
        }        
        return ans;
    }
};