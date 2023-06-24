int dp[13][1<<13];
class Solution {
public:
    int n;
    int find(int i, int vis, vector<vector<int>>& g){
        if(dp[i][vis]!=-1){ return dp[i][vis]; }
        if((vis&(vis-1))==0){ return 0; }
        dp[i][vis]=1e9;
        for(auto j:g[i]){
            if((vis&(1<<j))!=0){
                int alreadyVisited;
                if(dp[j][vis]!=-1){ alreadyVisited = dp[j][vis]; }
                else{ alreadyVisited = find(j,vis,g); }
                int notVisited;
                if(dp[j][vis^(1<<i)]!=-1){ notVisited = dp[j][vis^(1<<i)]; }
                else{ notVisited = find(j,vis^(1<<i),g); }
                int betterOption = min(alreadyVisited , notVisited);
                dp[i][vis] = min(dp[i][vis] , 1+betterOption);
            }
        }
        return dp[i][vis];
    }
    int shortestPathLength(vector<vector<int>>& g) {
        n=g.size();
        memset(dp,-1,sizeof(dp));
        int ans=1e9;
        for(int i=0; i<n; i++){
            ans=min(ans,find(i,((1<<n)-1),g));
        }
        return ans;
    }
};