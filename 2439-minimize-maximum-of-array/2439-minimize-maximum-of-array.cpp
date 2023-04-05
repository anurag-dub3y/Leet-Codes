class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int ans = 0;
        long long sum = 0;
        for (int i = 0; i < int(nums.size()); i ++) {
            sum += nums[i];
            int tmp = (sum + i) / (i + 1);
            ans = max(ans, tmp);
        }
        return ans;
    }
};