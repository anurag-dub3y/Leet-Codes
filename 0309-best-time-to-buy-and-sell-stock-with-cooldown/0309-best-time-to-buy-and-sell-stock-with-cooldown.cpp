class Solution {
public:
    int dp[5003][2];
    int dfs(vector<int>& prices, int ind, bool hold){
        if(ind>=prices.size()){ return 0; }
        if(dp[ind][hold]!=-1){ return dp[ind][hold]; }
        if(!hold){
            int buy = dfs(prices,ind+1,true)-prices[ind];
            int notbuy = dfs(prices,ind+1,false);
            return dp[ind][hold] = max(buy,notbuy);
        }
        int sell = dfs(prices,ind+2,false)+prices[ind];
        int notsell = dfs(prices,ind+1,true);
        return dp[ind][hold] = max(sell,notsell);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return dfs(prices,0,false);
    }
};