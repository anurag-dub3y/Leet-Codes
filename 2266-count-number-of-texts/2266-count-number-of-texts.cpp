class Solution {
public:
    int dp[100005], mod=1e9+7;
    int findWays(int i, string &s){
        if(i==s.length()){ return 1; }
        if(dp[i]!=-1){ return dp[i]; }
        int ans=0;
        if(s[i]>='2' and s[i]<='8' and s[i]!='7'){ 
            ans=findWays(i+1,s)%mod;
            if(i+1<s.length() and s[i+1]==s[i]){
                ans=(1LL*ans+findWays(i+2,s))%mod;
            }
            if(i+2<s.length() and s[i+1]==s[i] and s[i+2]==s[i]){
                ans=(1LL*ans+findWays(i+3,s))%mod;
            }
        }
        else{ 
            ans=findWays(i+1,s)%mod;
            if(i+1<s.length() and s[i+1]==s[i]){
                ans=(1LL*ans+findWays(i+2,s))%mod;
            }
            if(i+2<s.length() and s[i+1]==s[i] and s[i+2]==s[i]){
                ans=(1LL*ans+findWays(i+3,s))%mod;
            }
            if(i+3<s.length() and s[i+1]==s[i] and s[i+2]==s[i] and s[i+3]==s[i]){
                ans=(1LL*ans+findWays(i+4,s))%mod;
            }
        }
        return dp[i]=ans;
    }
    int countTexts(string pressedKeys) {
        memset(dp,-1,sizeof(dp));
        return findWays(0,pressedKeys);
    }
};