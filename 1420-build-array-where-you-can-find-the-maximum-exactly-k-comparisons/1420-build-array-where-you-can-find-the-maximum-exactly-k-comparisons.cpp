class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][101];
    int find(int i, int n, int m, int k, int mxYet){
        if(i==n){ return k==0; }
        if(k<0){ return 0; }
        int &ans=dp[i][k][mxYet];
        if(ans!=-1){ return ans; }
        ans=0;
        for(int j=1; j<=m; j++){
            if(j>mxYet){
                ans=(1LL*ans+find(i+1,n,m,k-1,j))%mod;    
            }
            else{
                ans=(1LL*ans+find(i+1,n,m,k,mxYet))%mod;
            }
        }
        return ans;
    }
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return find(0,n,m,k,0);
    }
};