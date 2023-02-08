class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int mod=1e9+7;
        vector<vector<long long>> dp(goal+1,vector<long long>(n+1,0));
        dp[0][0]=1;
        for(int i=1; i<=goal; i++){
            for(int j=1; j<=n; j++){
                // Selecting one (new) song from (n-j+1) songs that haven't been used yet
                dp[i][j]=dp[i-1][j-1]*(n-j+1);
                if(j>k){
                    // We can listen to a songs again (having listened k songs before)
                    dp[i][j]+=dp[i-1][j]*(j-k);
                }
                dp[i][j]%=mod;
            }
        }
        return dp[goal][n];
    }
};


