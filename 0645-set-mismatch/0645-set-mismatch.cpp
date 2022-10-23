class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int currSum=accumulate(nums.begin(),nums.end(),0);
        int originalSum=n*(n+1)/2;
        vector<int> v(2);
        for(int i=1; i<n; i++){ if(nums[i]==nums[i-1]){ v[0]=nums[i-1]; break; } }
        if(originalSum>currSum){ v[1]=v[0]+(originalSum-currSum); }
        else{ v[1]=v[0]-(currSum-originalSum); }
        return v;
    }
};