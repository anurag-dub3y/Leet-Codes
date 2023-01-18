class Solution {
public:
    // vector<vector<int>> dp;
    map<pair<int,int>,int> dp;
    int dfs(int i, int target, vector<int>& nums){
        if(i==nums.size()){ return target==0; }
        if(dp.find({i,target})!=dp.end()){ return dp[{i,target}]; }
        return dp[{i,target}]=dfs(i+1,target-nums[i],nums)+dfs(i+1,target+nums[i],nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // dp.resize(n+1,vector<int>(target+1,0));
        return dfs(0,target,nums);
    }
};