class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            sum += abs(nums[i] - nums[i-1]);
        }
        int case1 = sum, case2 = sum;
        for (int i = 1; i < n; i++) {
            case1 = max(case1, sum - abs(nums[i] - nums[i-1]) + abs(nums[i] - nums[0]));
            case2 = max(case2, sum - abs(nums[i] - nums[i-1]) + abs(nums[i-1] - nums.back()));
        }
        int ans = max(sum, max(case1, case2));
        int left = INT_MAX, right = INT_MIN; 
        for (int i = 1; i < n; i++) {
            left = min(left, max(nums[i], nums[i-1]));
            right = max(right, min(nums[i], nums[i-1]));
        }
        return max(ans, sum + 2 * (right - left));
    }
};