class Solution {
public:
    int countSquares(vector<vector<int>>& dp) {
        int m=dp.size(), n=dp[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j]==1 && i>0 && j>0){
                    dp[i][j]+=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};