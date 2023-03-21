// https://www.youtube.com/watch?v=fvYlinirmFg
class Solution {
public:
    const long long mod=1e9+7;
    int countPalindromicSubsequences(string s) {
        int n=s.length();
        vector<int> prev(n+1), next(n+1);
        map<char,int> m;
        for(int i=0; i<n; i++){
            if(m.count(s[i])==0){ prev[i]=-1; }
            else{ prev[i]=m[s[i]]; }
            m[s[i]]=i;
        }
        m.clear();
        for(int i=n-1; i>=0; i--){
            if(m.count(s[i])==0){ next[i]=n; }
            else{ next[i]=m[s[i]]; }
            m[s[i]]=i;
        }
        
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0LL));
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; i++, j++){
                if(g==0){ dp[i][j]=1; continue; }
                else if(g==1){ dp[i][j]=2; continue; }
                if(s[i]!=s[j]){
                    dp[i][j]=(1LL*mod+dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1])%mod;
                }
                else{
                    int n=next[i], p=prev[j];
                    if(n>p){
                        dp[i][j]=(2LL*dp[i+1][j-1]+2)%mod;
                    }
                    else if(n==p){
                        dp[i][j]=(2LL*dp[i+1][j-1]+1)%mod;
                    }
                    else{
                        dp[i][j]=(2LL*dp[i+1][j-1]-dp[n+1][p-1]+mod)%mod;
                    }
                }
            }
        }
        return dp[0][n-1]%mod;
    }
};

