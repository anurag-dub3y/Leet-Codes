class Solution {
public:
    int dp[200004];
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        memset(dp,0,sizeof(dp));
        int ans=1;
        for(auto &i:arr){
            i+=100001;
            dp[i]=max(dp[i],1+dp[i-difference]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};