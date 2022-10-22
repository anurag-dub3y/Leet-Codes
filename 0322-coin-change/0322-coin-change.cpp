class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int k=coins.size();
        vector<long long> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<k; j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        return dp[amount]>=INT_MAX?-1:dp[amount];
    }
};