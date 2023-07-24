class Solution {
public:
    using vii=array<int,3>;
    // using vii=vector<int>;
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fees) {
        int n=fees.size();
        // set<pair<int,int>> visitedEdge;
        // sort(begin(edges),end(edges),[&](const vector<int> &e1, const vector<int> &e2){
        //     return e1[2]<e2[2];    
        // });
        // unordered_map<int,unordered_map<int,int>> g;
        // for(auto &e:edges){
        //     if(visitedEdge.count({e[0],e[1]}) or visitedEdge.count({e[1],e[0]})){
        //         g[e[0]][e[1]]=g[e[1]][e[0]]=min(g[e[0]][e[1]],e[2]);
        //     }
        //     else{
        //         g[e[0]][e[1]]=g[e[1]][e[0]]=e[2];
        //         visitedEdge.insert({e[0],e[1]});
        //         visitedEdge.insert({e[1],e[0]});
        //     }
        // }
        vector<unordered_map<int,int>> g(n);
        for(auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            if (g[u].count(v)) {  g[u][v] = g[v][u] = min(g[u][v], t); } 
            else { g[u][v] = g[v][u] = t; }
        }
        priority_queue<vii,vector<vii>,greater<vii>> pq;
        
        vector<int> time(n,maxTime+1);
        time[0]=0;
        pq.push({fees[0],0,0});
        while(!pq.empty()){
            auto [cost,currTime,u]=pq.top(); pq.pop();
            if(u==n-1){ return cost; }
            for(auto &[e,w]:g[u]){
                int newTime=currTime+w, newCost=cost+fees[e];
                if(newTime<time[e]){
                    time[e]=newTime;
                    pq.push({newCost,newTime,e});
                }
            }
        }
        return -1;
    }
};