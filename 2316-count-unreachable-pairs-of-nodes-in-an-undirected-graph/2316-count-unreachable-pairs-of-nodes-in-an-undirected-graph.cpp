class Solution {
public:
    vector<long long> adj[100005];
    long long vis[100005]={0};
    int dfs(int n){
        vis[n]=1;
        int ans=1;
        for(auto i:adj[n]){
            if(!vis[i]){ ans+=dfs(i); }
        }
        return ans;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long> v;
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0], v=edges[i][1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        // vector<int> vis={0};
        for(int i=0; i<n; i++){
            if(!vis[i]){ v.push_back(dfs(i)); }
        }
        long long sum=accumulate(v.begin(),v.end(),0);
        long long ans=0;
        for(int i=0; i<v.size(); i++){
            ans+=(v[i]*v[i]);
        }
        sum=sum*sum;
        return (sum-ans)/2;
    }
};