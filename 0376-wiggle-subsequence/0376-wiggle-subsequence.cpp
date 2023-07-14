int dp[1001][1001][2];
class Solution {
public:
    int find(int val, int ind, int prev, vector<int>& nums){
        if(ind==nums.size()){ return 0; }
        if(dp[val][ind][prev]!=-1){ return dp[val][ind][prev]; }
        int ans=0;
        for(int i=ind; i<nums.size(); i++){
            if(nums[i]>val and prev==0){
                ans=max(ans,1+find(nums[i],i,1,nums));
            }
            else if(nums[i]<val and prev==1){
                ans=max(ans,1+find(nums[i],i,0,nums));
            }
        }
        return dp[val][ind][prev]=ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            ans=max({ans,1+find(nums[i],i+1,0,nums),1+find(nums[i],i+1,1,nums)});
        }
        return ans;
    }
};