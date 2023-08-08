class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, h=n-1;
        while(l<h){
            int midInd=(l+h)/2;
            if(nums[midInd]>nums[h]){ l=midInd+1; }
            else{ h=midInd; }
        }
        int placesRotated=l;
        l=0, h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            int realMid=(mid+placesRotated)%n;
            if(nums[realMid]==target){ return realMid; }
            if(nums[realMid]>target){ h=mid-1; }
            else{ l=mid+1; }
        }
        return -1;
    }
};