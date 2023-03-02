class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        for(auto &s:strs){
            int ones=count(s.begin(),s.end(),'1'), zeroes=s.length()-ones;
            for(int i=m; i>=zeroes; i--){
                for(int j=n; j>=ones; j--){
                    // if(i-zeroes<0 or j-ones<0){ continue; }
                    dp[i][j]=max(dp[i][j],1+dp[i-zeroes][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};