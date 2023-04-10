class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> ans(nums.size(),0LL);
        unordered_map<int, long long> lSum, rSum, lCnt, rCnt;    
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] += lCnt[nums[i]]*i - lSum[nums[i]];
            lSum[nums[i]] += i;
            ++lCnt[nums[i]];
        }  
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans[i] += rSum[nums[i]] - rCnt[nums[i]] * i;
            rSum[nums[i]] += i;
            ++rCnt[nums[i]];
        }
        return ans;
    }
};