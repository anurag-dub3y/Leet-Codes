class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        int val = 1;
        while(val*val<=n) {
            int sq = val*val;
            for(int i = sq; i < n+1; i++) {
                dp[i] = min(dp[i-sq] + 1,dp[i]);
            }
            val++;
        }
    return dp[n];
    }
};