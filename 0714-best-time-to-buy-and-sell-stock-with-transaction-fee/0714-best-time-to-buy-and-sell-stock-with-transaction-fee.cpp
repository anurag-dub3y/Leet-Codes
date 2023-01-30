class Solution {
public:
    int dp[50004][2];
    int dfs(int i, int state, vector<int>& p, int fee){
        if(i>=p.size()){ return 0; }
        if(dp[i][state]!=-1){ return dp[i][state]; }
        if(state==0){
            int buy=-p[i]-fee+dfs(i+1,1,p,fee);
            int notBuy=dfs(i+1,0,p,fee);
            return dp[i][state]=max(buy,notBuy);
        }
        else{
            int sell=p[i]+dfs(i+1,0,p,fee);
            int notSell=dfs(i+1,1,p,fee);
            return dp[i][state]=max(sell,notSell);
        }
    }
    int maxProfit(vector<int>& p, int fee) {
        memset(dp,-1,sizeof(dp));    
        return dfs(0,0,p,fee);
    }
};