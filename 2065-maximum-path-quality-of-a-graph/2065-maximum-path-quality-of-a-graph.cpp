typedef array<long long,3> vii;
typedef pair<int,int> pii;
class Solution {
public:
    vector<pair<int,int>> g[1003];
    vector<int> path;
    vector<int> djikstra(int n){
        const int inf = 1e9;
        vector<int> dist(n + 1, inf);
        vector<bool> vis(n + 1, false);
        dist[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.emplace(0, 0);
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
    int ans=0;
    int dfs(int i, int currTime, int maxTime, vector<int>& values, unordered_set<int> &curr){
        if(currTime+path[i]>maxTime){ return 0; }
        int x=0;
        for(auto &[v,wt]:g[i]){
            if(wt+path[v]+currTime>maxTime){ continue; }
            if(curr.count(v)){
                x=max(x,dfs(v,wt+currTime,maxTime,values,curr)); 
            }
            else{
                curr.insert(v);
                x=max(x,values[v]+dfs(v,wt+currTime,maxTime,values,curr));
                curr.erase(v);
            }
        }
        return x;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        for(auto &e:edges){
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        path=djikstra(n);
        unordered_set<int> curr;
        return max(values[0],dfs(0,0,maxTime,values,curr));
    }
};


