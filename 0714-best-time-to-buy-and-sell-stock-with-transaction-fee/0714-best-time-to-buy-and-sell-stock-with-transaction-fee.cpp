class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int dp[p.size()+1][2];
        memset(dp,-1,sizeof(dp));    
        function<int(int,int)> dfs=[&](int i, int state){
            if(i>=p.size()){ return 0; }
            if(dp[i][state]!=-1){ return dp[i][state]; }
            if(state==0){
                int buy=-p[i]-fee+dfs(i+1,1);
                int notBuy=dfs(i+1,0);
                return dp[i][state]=max(buy,notBuy);
            }
            else{
                int sell=p[i]+dfs(i+1,0);
                int notSell=dfs(i+1,1);
                return dp[i][state]=max(sell,notSell);
            }
        };
        return dfs(0,0);
    }
};