class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int>unique;
        for(int i: nums) unique.insert(i);
        int n = nums.size();
        nums.clear();
        for(int i: unique) nums.push_back(i);
        int ans = n - 1;
        for(int i = 0; i<nums.size(); i++) {
            int en = nums[i] + n - 1;
            int idx = upper_bound(nums.begin(), nums.end(), en) - nums.begin();
            int continuousLen = idx - i;
            ans = min(ans, n - continuousLen);
        }
        return ans;
    }
};