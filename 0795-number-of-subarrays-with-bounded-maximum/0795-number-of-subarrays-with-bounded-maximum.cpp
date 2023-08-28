class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int l=-1, r=-1, ans=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>right){ l=i; }   // Boundary reset
            if(nums[i]>=left){ r=i; }   // Include current one or not
            ans+=r-l;
        }
        return ans;
    }
};