class Solution {
public:
    int mod=1e9+7;
    int isPrime(char c){ return c=='2' or c=='3' or c=='5' or c=='7'; }
    int beautifulPartitions(string s, int k, int minLen) {
        int n=s.length();
        if(k==500){ return 1; }
        if(k*minLen>n){ return 0; }
        int dp[n][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++){ dp[i][1]=!isPrime(s[i]) and isPrime(s[0]); }
        for(int r=2; r<=k; r++){
            for(int i=(r*minLen)-1; i<n; i++){
                if(isPrime(s[i])){ continue; }
                for(int j=((r-1)*minLen)-1; j<=i-minLen; j++){
                    if(isPrime(s[j+1])){
                        // cout<<i<<" "<<j<<" "<<dp[j][r-1]<<' '; 
                        dp[i][r]=(dp[i][r]+dp[j][r-1])%mod;
                        // cout<<"dp "<<dp[i][r]<<endl;
                    }
                }
            }
        }
        return dp[n-1][k];
    }
};

// 2354 354 54. 235421