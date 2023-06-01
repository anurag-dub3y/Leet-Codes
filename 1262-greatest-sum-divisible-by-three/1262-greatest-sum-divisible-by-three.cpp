class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>> dp(n+1, vector<int>(3,0));
       dp[0][0] = 0;
       dp[0][1] = INT_MIN;
       dp[0][2] = INT_MIN; 
       for(int i = 1; i <= n; i++){
           int ind = i-1;
           dp[i][0] = max(dp[i-1][0], dp[i-1][(nums[ind]) % 3] + nums[ind]);
           dp[i][1] = max(dp[i-1][1], dp[i-1][(nums[ind]+1) % 3] + nums[ind]);
           dp[i][2] = max(dp[i-1][2], dp[i-1][(nums[ind]+2) % 3] + nums[ind]);
       }
       return dp[n][0];
    }
};