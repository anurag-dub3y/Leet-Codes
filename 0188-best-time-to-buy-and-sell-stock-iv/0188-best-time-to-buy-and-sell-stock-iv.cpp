class Solution {
public:
    int dp[100005][202];
    int dfs(int i, int stage, int k, vector<int>& prices){
        if(i==prices.size() or stage==2*k){ return 0; }

        if(dp[i][stage]!=-1){ return dp[i][stage]; }
        
        // Ignore current stock
        int ans=dfs(i+1,stage,k,prices);
        
        // Buy current stock if we can
        if(stage%2==0){
            ans=max(ans,-prices[i]+dfs(i+1,stage+1,k,prices));
        }
        
        // sell the current stock if we can
        else if(stage%2==1){
            ans=max(ans,prices[i]+dfs(i+1,stage+1,k,prices));
        }
        
        return dp[i][stage]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,k,prices);
    }
};
