class Graph {
public:
    vector<vector<pair<int,int>>> g;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        g.resize(n+1);
        for(auto e:edges){
            g[e[0]].push_back({e[1],e[2]});
        }
    }
    
    void addEdge(vector<int> e) {
        g[e[0]].push_back({e[1],e[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,node1});
        vector<int> vis(N,0);
        while(!pq.empty()){
            auto [d,i]=pq.top(); pq.pop();
            vis[i]=1;
            if(i==node2){ return d; }
            for(auto [j,w]:g[i]){
                if(!vis[j]){
                    pq.push({d+w,j});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */