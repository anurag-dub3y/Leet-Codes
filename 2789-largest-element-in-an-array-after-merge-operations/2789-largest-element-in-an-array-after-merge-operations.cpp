class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
//         vector<long long> pre={0};
//         for(auto &i:nums){ pre.push_back(pre.back()+i); }
//         auto it=max_element(begin(nums),end(nums));
        int n=nums.size();
        long long ans=nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i]>ans){ ans=nums[i]; }
            else{ ans+=nums[i]; }
        }
        return ans;
    }
};