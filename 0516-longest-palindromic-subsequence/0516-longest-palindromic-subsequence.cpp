class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=size(s);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string t=s;
        reverse(begin(t),end(t));
        // for(int i=n-1; i>=0; i--){
        //     for(int j=n-1; j>=0; j--){
        //         dp[i][j]=(s[i]==t[j])? 1+dp[i+1][j+1]: max(dp[i+1][j],dp[i][j+1]);
        //     }
        // }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dp[i][j]=(s[i-1]==t[j-1])? 1+dp[i-1][j-1]: max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};