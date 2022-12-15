class Solution {
public:
    int dp[4][3][5003];
    int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    int mod=(int)1e9+7;
    int dfs(int i, int j, int n){
        if(i<0 or j<0 or i>=4 or j>=3 or (i==3 and j!=1)){ return 0; }
        if(n==1){ return 1; }
        if(dp[i][j][n]!=-1){ return dp[i][j][n]; }
        int ans=0;
        for(int dd=0; dd<8; dd++){
            ans=(ans+dfs(i+X[dd],j+Y[dd],n-1))%mod;
        }
        return dp[i][j][n]=ans%mod;
    }
    int knightDialer(int n) {
        memset(dp,-1,sizeof(dp));
        long long ans=0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                ans=(ans+dfs(i,j,n))%mod;
            }
        }
        return (int)ans;
    }
};