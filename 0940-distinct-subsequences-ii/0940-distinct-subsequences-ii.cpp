class Solution {
public:
    int distinctSubseqII(string &s) {
        int n=s.length(),mod=1e9+7;
        vector<int> dp(n+1,0);
        dp[0]=1;
        map<char,int> mp;
        for(int i=1; i<=n; i++){
            dp[i]=(2LL*dp[i-1])%mod;
            if(mp[s[i-1]]!=0){
                int temp=dp[mp[s[i-1]]-1];
                dp[i]=(dp[i]+mod-temp)%mod;
            }
            mp[s[i-1]]=i;
        }
        return (dp[n]+mod-1)%mod;
    }
};