class Solution {
public:
    int tallestBillboard(vector<int>& nums) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<int> dp(sum+1,-1), curr;
        // dp[x] is max(x1,x2) such that abs(x1-x2)=x
        // where x1 and x2 are the supports
        
        dp[0]=0;
        for(int &el: nums){
            curr=dp;
            for(int i=0; i<=sum-el; ++i){
                
                // If current difference has not been visited before
                if(curr[i]<0){ continue; }
                
                // putting rod into highest side
                dp[i+el]=max(dp[i+el],curr[i]);
                
                // putting rod into smallest side
                dp[abs(i-el)]=max(dp[abs(i-el)],curr[i]+min(i,el));
            }
        }
        
        return dp[0];
    }
};