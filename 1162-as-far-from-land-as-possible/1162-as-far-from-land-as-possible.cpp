class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int INF=201;
        vector<vector<int>> dp(m,vector<int>(n,INF));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){ dp[i][j]=0; continue; }
                else{
                    if(i>0){ dp[i][j]=min(dp[i][j],1+dp[i-1][j]); }
                    if(j>0){ dp[i][j]=min(dp[i][j],1+dp[i][j-1]); }
                }
            }
        }
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(grid[i][j]==1){ continue; }
                else{
                    if(i<m-1){ dp[i][j]=min(dp[i][j],1+dp[i+1][j]); }
                    if(j<n-1){ dp[i][j]=min(dp[i][j],1+dp[i][j+1]); }
                }
            }
        }
        int ans=-1;
        for(auto ele:dp){
            for(auto i:ele){ ans=max(ans,i); }
        }
        return ans==201 or ans==0?-1:ans;
    }
};