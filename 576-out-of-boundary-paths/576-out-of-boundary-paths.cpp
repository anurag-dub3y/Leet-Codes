class Solution {
public:
    int dp[51][51][51];
    int mod=1e9+7;
    int ans=0;
    int dir[5]={-1,0,1,0,-1};
    int findPaths(int m, int n, int maxMove, int sR, int sC) {
        for(int k=1; k<=maxMove; k++){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    for(int x=0; x<4; x++){
                        int I=i+dir[x], J=j+dir[x+1];
                        if(I<0 or J<0 or I>=m or J>=n){
                            dp[i][j][k]=(1+dp[i][j][k])%mod;
                        }
                        else{
                            dp[i][j][k]=(dp[i][j][k]+dp[I][J][k-1])%mod;
                        }
                    }
                }
            }
        }
        return dp[sR][sC][maxMove];
    }
};