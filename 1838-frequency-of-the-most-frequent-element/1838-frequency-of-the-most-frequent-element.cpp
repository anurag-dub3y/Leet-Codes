class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 1, i = 0, j;
        long sum = 0;
        sort(nums.begin(),nums.end());
        for(i=0; i<nums.size(); i++){
            sum+=nums[i];
            while(sum + k < (long)nums[i]*(i - j + 1)){         // i-j+1 is window size 
                                                                // Sum+k means if we add k to the window sum, will it be less than/equal to the hypothetical sum of when all elements in window were nums[i]
                sum-=nums[j++]; 
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};