class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int n1=a.size(), n2=b.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        // int i=0, j=0;
        int ans=0;
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                if(a[i]==b[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};