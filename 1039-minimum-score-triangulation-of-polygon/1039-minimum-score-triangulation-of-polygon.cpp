class Solution {
public:
    int dp[51][51];
    int memo(int i, int j, vector<int>& v){
        if(i>=j){ return 0; }
        if(dp[i][j]!=-1){ return dp[i][j]; }
        dp[i][j]=INT_MAX;
        for(int k=i; k<j; k++){
            dp[i][j]=min(dp[i][j], memo(i,k,v) + memo(k+1,j,v) + v[i-1]*v[k]*v[j]);
        }
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        return memo(1,values.size()-1,values);
    }
};