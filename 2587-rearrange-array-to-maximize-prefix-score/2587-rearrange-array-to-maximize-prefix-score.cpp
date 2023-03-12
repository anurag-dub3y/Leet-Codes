class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum=0,ans=0;
        int n=nums.size(),i;
        for(i=0;i<n;i++){
            if(nums[i]<=0) break;
            sum += nums[i];
        }
        ans = i;
        while(i<n ){
            sum += nums[i++];
            if(sum > 0){ ans++; }
        }
        return ans;
    }
};