class Solution {
public:
    int dp[100005];
    int minOperations(int n) {
        dp[0]=0;
        for(int i=1; i<=n; i++){
            dp[i]=20;
            for(int j=0; j<20; j++){
                int t = i - (1<<j);
                if(t<0){ t=-t; }
                if(t<i){
                    dp[i]=min(dp[i],dp[t]+1);
                }
            }
        }
        return dp[n];
    }
};

