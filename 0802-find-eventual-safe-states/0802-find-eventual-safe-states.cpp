class Solution {
public:
//     void find(int i, vector<int> &deg, vector<int> &ans, vector<int> &vis, vector<vector<int>>& graph, int &f){
//         int n=graph.size();
//         vis[i]=1;
//         int cnt=0;
//         bool x=false;
//         for(auto j:graph[i]){
//             if(deg[j]==0){ cnt++; }
            
//         }
//         if(cnt==graph[i].size()){ f=1; }
//         else{ f=0; }
//         ans[i]=1;
//     }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<int> q;
        vector<vector<int>> k(n);
        vector<int> deg(n,0), w(n,0);
        for(int i=0; i<n; i++){
            for(auto j:graph[i]){ k[j].push_back(i); }
        }
        for(int i=0; i<n; i++){
            deg[i]=graph[i].size();
            if(deg[i]==0){ q.push(i); }      // Terminal Node
        }
        while(!q.empty()){
            int front=q.front(); q.pop();
            w[front]=1;
            for(auto j:k[front]){
                if(--deg[j]==0){ q.push(j); }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(w[i]){ ans.push_back(i); }
        }
        return ans;
    }
};