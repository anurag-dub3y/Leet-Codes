class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=*max_element(begin(nums),end(nums));
        int ans=1, curr=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1] and nums[i]==mx){ curr++; ans=max(ans,curr); }
            else{ curr=1; }
        }
        return ans;
    }
};