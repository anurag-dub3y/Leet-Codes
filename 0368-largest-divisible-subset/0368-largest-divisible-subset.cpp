class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(n);
        int ind=0, maxLen=0;
        // dp[0]={nums[0]};
        for(int i=0; i<n; i++){
            dp[i]={nums[i]};
            for(int j=i-1; j>=0; j--){
                if((nums[i]%nums[j]==0 or nums[j]%nums[i]==0) && dp[i].size()<dp[j].size()+1){ 
                    dp[i]=dp[j]; dp[i].push_back(nums[i]); 
                }
            }
            if(dp[i].size()>maxLen){ ind=i; maxLen=dp[i].size(); }
        }
        return dp[ind];
    }
};