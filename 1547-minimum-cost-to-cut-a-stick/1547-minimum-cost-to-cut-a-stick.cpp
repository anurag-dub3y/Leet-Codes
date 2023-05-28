class Solution {
public:
    int dp[100][100];
    int total_cost(int lb,int ub,vector<int>& cuts,int li,int ui){
         if(ui == li) return ub-lb;
         if(ui < li) return 0;
         if(dp[li][ui] != -1) return dp[li][ui];
         int ans = INT_MAX;
         for(int i = li;i <= ui;i++) {
            int a = ub-lb+total_cost(cuts[i],ub,cuts,i+1,ui)+total_cost(lb,cuts[i],cuts,li,i-1);
            ans = min(ans,a);   
         }
         return dp[li][ui] = (ans == INT_MAX ? 0 : ans);
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
       return total_cost(0,n,cuts,0,cuts.size()-1);
    }
};