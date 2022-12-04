class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long int currentSum = 0, totalSum = 0, minSum = INT_MAX, avgDiff = 0, minIndex = 0;
        for(auto i: nums){ totalSum += i; }
        for(int i=0; i<n; i++) {
            currentSum += nums[i];
            if(i == n-1){ avgDiff = abs(currentSum / (i+1)); }
            else{ avgDiff = abs((currentSum / (i+1)) - ((totalSum-currentSum) / (n-i-1))); }
            if(avgDiff < minSum) {
                minSum = avgDiff;
                minIndex = i;
            }
        }
        return minIndex;
    }
};