class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(), ans=0;
        unordered_map<int,unordered_map<long,int>> dp;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                long diff=(long)nums[i]-(long)nums[j], sum=0;
                if(dp[j].count(diff)!=0){
                    sum=dp[j][diff];
                }
                dp[i][diff]+=(sum+1);   // dp[i][diff] has a min value of 1 (meaning it is the AP with 2 elements)
                ans+=sum;   // when adding to ans, we won't add the AP of size 2
            }
        }
        return ans;
    }
};