class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        if(is_sorted(begin(nums),end(nums))){ return 0; }
        long long ans=0;
        int n=nums.size();
        int prev=nums.back();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<=prev){ prev=nums[i]; }
            else{
                ans+=(ceil((nums[i]+prev-1)/prev))-1;
                prev=nums[i]/(ceil((nums[i]+prev-1)/prev));
            }
        }
        return ans;
    }
};

// 9 - (6,3) - (3,3,3)
// 18 - (15,3) - (12,3,3) - (9,3,3,3) - (6,3,3,3,3) - (3,3,3,3,3,3)
// 17 - (14,3) - (11,3,3) - (8,3,3,3) - (5,3,3,3,3) - (2,3,3,3,3,3)