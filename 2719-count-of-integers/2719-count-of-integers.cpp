class Solution {
public:
    int mod=1e9+7;
    int dp[23][2][2][404];
    int findWays(int i, bool isMin, bool isMx, int currSum, string &num1, string &num2){
        if(currSum<0){ return 0; }
        if(i==num1.length()){ return 1; }
        if(dp[i][isMin][isMx][currSum]!=-1){ return dp[i][isMin][isMx][currSum]; }
        int ans=0;
        // num1[i] can be any value between lowestPossible and highestPossible
        int lowestPossible=isMin?num1[i]-'0':0, highestPossible=isMx?num2[i]-'0':9;
        for(int ind=lowestPossible; ind<=highestPossible; ind++){
            bool v1=(ind==lowestPossible), v2=(ind==highestPossible);
            // v1=true implies we must choose num1[i] here
            ans=(1LL*ans+findWays(i+1, isMin and v1, isMx and v2, currSum-ind, num1, num2)%mod)%mod;
        }
        return dp[i][isMin][isMx][currSum]=ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        int sizeDif=num2.length()-num1.length();
        num1=string(sizeDif,'0')+num1;
        
        // We are checking from max_sum to 0 strings
        int ub=findWays(0,1,1,max_sum,num1,num2);
        
        int lb=findWays(0,1,1,min_sum-1,num1,num2);
        
        return (ub-lb+mod)%mod;
    }
};