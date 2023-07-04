class Solution {
public:
    int numberOfUniqueGoodSubsequences(string &b) {
        int n=b.length(), mod=1e9+7;
        // map<int,int> index;
        // vector<int> dp(n+1,0);
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        bool foundZero=false;
        for(int i=n-1; i>=0; i--){
            if(b[i]=='0'){
                foundZero=true;
                dp[0][i]=(1LL*dp[0][i+1]+dp[1][i+1]+1LL)%mod;
                dp[1][i]=dp[1][i+1];
            }
            else{
                dp[0][i]=dp[0][i+1];
                dp[1][i]=(1LL*dp[0][i+1]+1LL+dp[1][i+1])%mod;
            }
        }
        return (dp[1][0]+foundZero)%mod;
    }
};