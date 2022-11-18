class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size(), sum=accumulate(stones.begin(),stones.end(),0);
        int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=n; i++){ dp[i][0]=1; }
        for(int i=1; i<=sum; i++){ dp[0][i]=0; }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                dp[i][j]=dp[i-1][j];
                if(stones[i-1]<=j){
                    dp[i][j] |= dp[i-1][j-stones[i-1]];
                }
            }
        }
        int ans=INT_MAX;
        for(int j=sum/2; j>=0; j--){
            if(dp[n][j]){ ans=sum-2*j; break; }
        }
        return ans;
    }
};