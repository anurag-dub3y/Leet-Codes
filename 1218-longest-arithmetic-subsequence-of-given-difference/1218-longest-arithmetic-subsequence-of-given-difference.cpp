class Solution {
public:
    int dp[200004];
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        memset(dp,0,sizeof(dp));
        // dp[0]=1;
        // dp[0]=1;
        // for(int i=1; i<n; i++){ dp[i]=1; }
        int ans=1;
        for(auto &i:arr){
            i+=100001;
            dp[i]=max(dp[i],1+dp[i-difference]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};