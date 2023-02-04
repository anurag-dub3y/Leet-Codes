class Solution {
public:
    bool backtrack(vector<int>& nums, int index, int target, vector<int>& buckets){
        if(index == nums.size()){ 
            for(auto b:buckets){
                if(b!=target){ return false; }
            }
            return true;
        }
        for(int i = 0, n = buckets.size(); i < n; i++){
            if(buckets[i] + nums[index] > target){ continue; }
            buckets[i] += nums[index];
            if(backtrack(nums, index+1, target, buckets)){ return true; }
            buckets[i] -= nums[index];
            if(buckets[i] == 0){ break; }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k > nums.size()) return false;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(k > sum || sum%k != 0) return false;
        sort(nums.begin(), nums.end(), greater<int>());
        int target = sum/k;
        vector<int> buckets(k, 0);
        return backtrack(nums, 0, target, buckets);
    }
};