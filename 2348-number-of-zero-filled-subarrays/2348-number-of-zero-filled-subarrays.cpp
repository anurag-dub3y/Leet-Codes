class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0, cnt=0;
        int i=0, j=0, n=nums.size();
        while(i<n){
            if(nums[i]==0){ cnt++; }
            else{ cnt=0; }
            ans+=cnt;
            i++;
        }
        return ans;
    }
};