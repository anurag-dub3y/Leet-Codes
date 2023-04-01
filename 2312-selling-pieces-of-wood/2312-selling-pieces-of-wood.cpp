class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp=vector<vector<long long>> (m+1,vector<long long>(n+1,0LL));
        for(auto p:prices){
            dp[p[0]][p[1]]=p[2];
        }
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                for(int h=1; h<=i/2; h++){
                    dp[i][j]=max(dp[i][j],dp[h][j]+dp[i-h][j]);
                }
                for(int w=1; w<=j/2; w++){
                    dp[i][j]=max(dp[i][j],dp[i][w]+dp[i][j-w]);
                }
            }
        }
        return dp[m][n];
    }
};