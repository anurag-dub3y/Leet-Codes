class Solution {
public:
    int dp[1001][1001];
    int find(int i, int target, vector<int>& nums){
        if(target==0){ return 0; }   
        if(target<0 or i >=nums.size()){ return -1001; }
        int &ans=dp[i][target];
        if(ans!=-1){ return ans;  }
        ans=1+find(i+1,target-nums[i], nums); 
        ans=max(ans,find(i+1,target,nums));
        return ans; 
    }
    
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = find(0,target,nums);
        return (ans>0)?ans:-1;
    }
};