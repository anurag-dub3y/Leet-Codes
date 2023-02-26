class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n=nums.size(), x=0, sum=accumulate(nums.begin(),nums.end(),0);
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            x+=nums[i];
            ans[i]=abs(x-sum);
            sum-=nums[i];
        }
        return ans;
    }
};