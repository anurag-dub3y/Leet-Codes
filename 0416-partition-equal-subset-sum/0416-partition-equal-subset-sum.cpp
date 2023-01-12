class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(), sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){ return false; }
        sum/=2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=0; i<=n; i++) { dp[i][0]=1; }
        
        for(int i=1; i<=n; i++) {
            for (int j=1; j<=sum; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= nums[i-1]) {
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
                }
            }
        }
       
        return dp[n][sum];
    }
};