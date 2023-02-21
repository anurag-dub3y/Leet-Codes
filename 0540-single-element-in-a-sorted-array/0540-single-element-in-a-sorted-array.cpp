class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1 or nums[0]!=nums[1]){ return nums[0]; }
        if(nums[n-1]!=nums[n-2]){ return nums[n-1]; }
        int left=0, right=n-1;
        while(left<right){
            int mid = (left+right)>>1;
            if((mid%2==0 && nums[mid]==nums[mid+1]) or (mid%2==1 && nums[mid]==nums[mid-1])){
                left=mid+1;
            }
            else{ right = mid; }
        }
        return nums[left];
    }
};