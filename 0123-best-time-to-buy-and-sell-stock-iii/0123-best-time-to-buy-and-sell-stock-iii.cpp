class Solution {
public:
    int dp[100005][5];
    int dfs(int i, int stage, vector<int>& prices){
        if(i==prices.size()){ return 0; }

        if(dp[i][stage]!=-1){ return dp[i][stage]; }
        
        // Ignore current stock
        int ans=dfs(i+1,stage,prices);
        
        // Buy current stock if we can
        if(stage==0 or stage==2){
            ans=max(ans,-prices[i]+dfs(i+1,stage+1,prices));
        }
        
        // sell the current stock if we can
        else if(stage==1 or stage==3){
            ans=max(ans,prices[i]+dfs(i+1,stage+1,prices));
        }
        
        return dp[i][stage]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,prices);
    }
};