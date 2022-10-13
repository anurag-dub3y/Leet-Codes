class Solution {
public:
    int mod=1e9+7, m, n, k;
    int numberOfPaths(vector<vector<int>>& g, int K) {
        m=g.size(), n=g[0].size(), k=K;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return dfs(0,0,0,g,dp);
    }
    int dfs(int i, int j, int sum, vector<vector<int>>& g, vector<vector<vector<int>>>& dp){
        if(i>=m or j>=n){ return 0; }
        if(i==m-1 && j==n-1){ return (sum+g[i][j])%k==0; }
        if(dp[i][j][sum]!=-1){ return dp[i][j][sum]; }
        return dp[i][j][sum]=(dfs(i+1,j,(sum+g[i][j])%k,g,dp)%mod+dfs(i,j+1,(sum+g[i][j])%k,g,dp)%mod)%mod;
    }
};