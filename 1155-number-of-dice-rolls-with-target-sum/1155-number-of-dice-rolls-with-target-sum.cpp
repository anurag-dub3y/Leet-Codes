class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        int mod = 1000000007;
        dp[0][0]=1;
        for(int sum=1; sum<=target; sum++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=k; j++){
                    if(j<=sum){
                        dp[i][sum]=((dp[i][sum]%mod)+(dp[i-1][sum-j]%mod))%mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};