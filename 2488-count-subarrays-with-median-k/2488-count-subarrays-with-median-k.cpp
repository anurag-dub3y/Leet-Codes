class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), ans=0, sum=0;
        int ind=find(nums.begin(),nums.end(),k)-nums.begin();
        unordered_map<int,int> u;
        u[0]=1; // Empty subarray
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>k){ sum++; }
            else if(nums[i]<k){ sum--; }
            if(i>=ind){ ans+=u[sum]+u[sum-1]; } // Only subarray with sum=0 and sum=-1 are allowed
            else{ u[sum]++; }
        }
        return ans;
    }
};