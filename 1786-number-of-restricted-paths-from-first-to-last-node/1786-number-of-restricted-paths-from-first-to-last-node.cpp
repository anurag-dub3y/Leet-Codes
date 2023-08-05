typedef pair<int,int> pii;
class Solution {
public:
    int mod=1000000007;
    vector<pii> g[20004];
    int dp[20004];
    int dfs(int i, int n, vector<int> &dist){
        if(i==n){ return 1; }
        if(dp[i]!=-1){ return dp[i]; }
        int ans=0;
        for(auto &[j,w]:g[i]){
            if(dist[j]<dist[i]){ ans=(1LL*ans+dfs(j,n,dist))%mod; }
        }
        return dp[i]=ans;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        for(auto &e:edges){
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        vector<int> dist(n+1,2e9);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,n});
        dist[n]=0;
        while(!pq.empty()){
            auto [d,i]=pq.top(); pq.pop();
            for(auto &[j,w]:g[i]){
                if(d+w<dist[j]){
                    dist[j]=d+w;
                    pq.push({d+w,j});
                }
            }
        }
        memset(dp,-1,sizeof(int)*(n+1));
        return dfs(1,n,dist);
    }
};