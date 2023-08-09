class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        auto check = [&](long long mid){
            if(nums.size()<4){ return true; }
            if(nums[n-1]-nums[3]<=mid or nums[n-2]-nums[2]<=mid 
               or nums[n-3]-nums[1]<=mid or nums[n-4]-nums[0]<=mid){ return true; }
            return false;
        };
        int low=0, high=nums.back()-nums[0];
        while(low<=high){
            long long mid=(1LL*low+high)/2;
            if(check(mid)){ high=mid-1; }
            else{ low=mid+1; }
        }
        return low;
    }
};


