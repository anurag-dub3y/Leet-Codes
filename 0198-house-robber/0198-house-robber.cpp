class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){ return nums[0]; }
        vector<int> dp(n+1,0);
        dp[1]=nums[0]; dp[2]=nums[1];
        for(int i=3; i<=n; i++){
            for(int j=0; j<i-1; j++){ dp[i]=max(dp[i],dp[j]+nums[i-1]); }
        }
        return *max_element(dp.begin(),dp.end());
    }
};