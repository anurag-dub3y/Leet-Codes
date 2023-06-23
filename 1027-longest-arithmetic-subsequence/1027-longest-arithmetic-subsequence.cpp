class Solution {
public:
    int longestArithSeqLength(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(1005,0));
        // unordered_map<pair<int,int>,int> dp;
        int ans=0;
        for(int i=2; i<=n; i++){
            for(int j=i-1; j>=1; j--){
                int d=500+nums[i-1]-nums[j-1];
                dp[i][d]=max(dp[i][d],1+dp[j][d]);
                ans=max(ans,dp[i][d]);
                // int d=nums[i-1]-nums[j-1];
                // dp[{i,d}]=max(dp[{i,d}],1+dp[{j,d}]);
                // ans=max(ans,dp[{i,d}]);
            }
        }
        return ans+1;
    }
};