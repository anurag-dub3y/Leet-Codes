class Solution {
public:
    int n, k, mod=1e9+7;
    int dp[101][101];
    int findWays(int i, int goal){
        if(goal==0){ return i>=n; }
        if(dp[i][goal]!=-1){
            return dp[i][goal];
        }
        // Choosing one unplayed song
        int ans=(1LL*(n-i)*findWays(i+1,goal-1))%mod;
        
        // Choosing one song thats been played previously
        if(i>k){
            ans=(1LL*ans+1LL*(i-k)*findWays(i,goal-1))%mod;
        }
        return dp[i][goal]=ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        this->n=n; this->k=k;
        memset(dp,-1,sizeof(dp));
        return findWays(0,goal);
    }
};