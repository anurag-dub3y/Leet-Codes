class Solution {
public:
    int minDistance(string p, string q) {
        int m=size(p), n=size(q); 
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0 && j==0){ dp[i][j]=0; }
                else if(i==0){ dp[i][j]=j; }
                else if(j==0){ dp[i][j]=i; }
                else{
                    if(p[i-1]==q[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                        dp[i][j]=min(dp[i][j],2+dp[i-1][j-1]);
                    }
                }
            }
        }
        return dp[m][n];
    }
};