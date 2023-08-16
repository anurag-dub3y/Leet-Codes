class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(2*nums[i]==target and nums[i+1]==nums[i]){ return {i+1,i+2}; }
            int lb=lower_bound(begin(nums),end(nums),target-nums[i])-begin(nums);
            if(lb==nums.size()){ continue; }
            if(nums[lb]+nums[i]==target){ return {i+1,lb+1}; }
        }
        return {};
    }
};