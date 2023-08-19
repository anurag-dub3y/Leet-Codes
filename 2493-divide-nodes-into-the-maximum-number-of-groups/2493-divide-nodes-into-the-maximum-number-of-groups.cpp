class Solution {
public:
    vector<int> adj[501];
    
    //function for checking whether a graph component is bipartite or not (for disconnected graph)
    bool bipartite(int src, vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()) {
            int node=q.front(); q.pop();
            for(auto &it:adj[node]) {
                if(color[it]==-1) {
                    color[it] = 1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]){ return false; }
            }
        }
        return true;  
    }
    
    //function for checking whether a graph is bipartite or not
    bool checkBipartite(int &n) {
        vector<int> color(n,-1);
        for(int i=0; i<n; i++) {
            if(color[i]==-1) {
                if(!bipartite(i, color)) return false;
            }
        }
        return true;
    }
    
    //Finding distance of farthest node from the current node
    int findFarthestDistBFS(int src, int n) {
        vector<int> vis(n, 0);
        queue<int> q; q.push(src);
        vis[src]=1;
        int cnt=0;
        while(!q.empty()) {
            int sz=q.size();
            cnt++;
            while(sz--) {
                int node = q.front(); q.pop();
                for(auto &it:adj[node]) {
                    if(!vis[it]) {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
        return cnt;
    }
    
    //Longest Chain in each component
    int dfsForComponents(int node, vector<int> &vist, vector<int> &dist){
        vist[node]=1;
        int ans=dist[node];
        for(auto it:adj[node]) {
            if(!vist[it]) {
                ans = max(ans, dfsForComponents(it, vist, dist));
            }
        }
        return ans;
    }
    
    int magnificentSets(int n, vector<vector<int>>& edges) {

        for(auto &e:edges){
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        
        //check whether a graph is bipartite or not
        if(!checkBipartite(n)){ return -1; }
        
        //calcuate farthest node from each node and store in dist vector
        vector<int> dist(n, 0);
        for(int i=0; i<n; i++) {
            dist[i] = findFarthestDistBFS(i, n);
        }
        
        //Count longest chain for each group
        vector<int> vist(n, 0);
        int ans=0;
        for(int i=0; i<n; i++) {
            if(vist[i]==0) {
                ans += dfsForComponents(i, vist, dist);
            }
        }
        return ans;
        
    }
};