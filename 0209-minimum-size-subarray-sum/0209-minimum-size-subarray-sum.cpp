class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0, j=0, curr=0, minLen=n+1;
        while(i<n){
            curr+=nums[i];
            while(curr>=target and j<=i){
                minLen=min(minLen,i-j+1);
                curr-=nums[j++];
            }
            i++;
        }
        return minLen==n+1?0:minLen;
    }
};