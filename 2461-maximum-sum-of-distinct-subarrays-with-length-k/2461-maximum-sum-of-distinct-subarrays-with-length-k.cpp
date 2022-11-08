class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        long long sum=0, mxm=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k){ mxm=max(mxm,sum); }
        for(int i=k;i<n;i++){  
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){ mp.erase(nums[i-k]); }
            sum-=nums[i-k];
            sum+=nums[i];
            mp[nums[i]]++;
            if(mp.size()==k){ mxm=max(mxm,sum); }
        }
        return mxm;
    }
};