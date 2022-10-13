class Solution {
public:
    int dp[201][201]={0};
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,0,sizeof(dp));
        dp[0][0]=grid[0][0];
        int m=grid.size(), n=grid[0].size();
        for(int j=1; j<n; j++){ dp[0][j]=grid[0][j]+dp[0][j-1]; }
        for(int i=1; i<m; i++){ dp[i][0]=grid[i][0]+dp[i-1][0]; }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};