class Solution {
public:
    unordered_map<int,int> dp;
    int mod=1e9+7;
    int numTilings(int n) {
        if(n<=2){ return n; }
        if(n==3){ return 5; }
        if(dp.find(n)!=dp.end()){ return dp[n]; }
        return dp[n]=((1LL*2*numTilings(n-1))%mod+(1LL*numTilings(n-3)%mod))%mod;
    }
};