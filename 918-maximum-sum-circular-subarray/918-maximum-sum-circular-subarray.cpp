class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=size(nums);
        int i=0, maxSum=nums[0], minSum=nums[0], posSum=0, negSum=0;
        while(i<n){
            posSum=max(posSum+nums[i],nums[i]);
            negSum=min(negSum+nums[i],nums[i]);
            maxSum=max(maxSum,posSum);
            minSum=min(minSum,negSum);
            i++;
        }
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(maxSum>0){
            return max(maxSum,totalSum-minSum);
        }
        return maxSum;
    }
};