int dp[501][501], mod=1e9+7;
class Solution {
public:
    int find(int i, int steps, int arrLen){
        if(steps==0){ return i==0; }
        if(dp[i][steps]!=-1){ return dp[i][steps]; }
        int ans=find(i,steps-1,arrLen)%mod;
        if(i>0){ ans=(1LL*ans+find(i-1,steps-1,arrLen))%mod; }
        if(i<arrLen-1){ ans=(ans+find(i+1,steps-1,arrLen))%mod; }
        return dp[i][steps]=ans;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return find(0,steps,arrLen);
    }
};