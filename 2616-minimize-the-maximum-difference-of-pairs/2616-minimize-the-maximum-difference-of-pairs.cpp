class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums),end(nums));
        int low=0, high=nums.back()-nums[0], ans;
        auto check=[&](const int &mid){
            int i=1, picked=0;
            while(i<nums.size()){
                if(nums[i]-nums[i-1]<=mid){ picked++; i+=2; }
                else{ i++; }
            }
            return picked>=p;
        };
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid)){
                ans=mid; high=mid-1;
            }
            else{ low=mid+1; }
        }
        return ans;
    }
};

// 1 1 2 3 7 10
// 12 13 

// 1 2 2 4
// 12 