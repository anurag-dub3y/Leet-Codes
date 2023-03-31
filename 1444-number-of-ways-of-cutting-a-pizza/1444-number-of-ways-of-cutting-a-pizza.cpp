class Solution {
public:
    const int mod=1e9+7;
    int m,n;
    vector<vector<int>> pre;
    int dp[55][55][15];
    int findWays(int r, int c, int cuts){
        if(pre[r][c]==0){ return 0; }
        if(cuts==0){ return 1; }
        if(dp[r][c][cuts]!=-1){ return dp[r][c][cuts]; }
        int ans=0;
        for(int nr=r+1; nr<m; nr++){
            if(pre[r][c]-pre[nr][c]>0){
                ans=(1LL*ans+findWays(nr,c,cuts-1))%mod;
            }
        }
        for(int nc=c+1; nc<n; nc++){
            if(pre[r][c]-pre[r][nc]>0){
                ans=(1LL*ans+findWays(r,nc,cuts-1))%mod;
            }
        }
        return dp[r][c][cuts]=ans;
    }
    int ways(vector<string>& p, int k) {
        m=p.size(), n=p[0].size();
        pre=vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                pre[i][j]=pre[i+1][j]+pre[i][j+1]-pre[i+1][j+1]+(p[i][j]=='A');
            }
        }
        memset(dp,-1,sizeof(dp));
        return findWays(0,0,k-1);
    }
};