class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){ return nums[0]; }
        vector<int> A(nums.begin(),nums.begin()+n-1);
        vector<int> B(nums.begin()+1,nums.end());
        return max(OGrob(A),OGrob(B));
    }
    int OGrob(vector<int>& nums){
        int n=nums.size();
        if(n==1){ return nums[0]; }
        vector<int> dp(nums);
        dp[1]=max(nums[0],nums[1]);
        for(int i=2; i<n; i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1];
    }
};