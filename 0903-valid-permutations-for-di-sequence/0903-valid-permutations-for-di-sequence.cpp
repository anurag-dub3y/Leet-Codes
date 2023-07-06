class Solution {
public:
    int n;
    int vis[202], dp[202][202], mod=1e9+7;
    int find(int i, int prev, string &s){
        if(i==s.length()){ return 1; }
        if(dp[i][prev]!=-1){ return dp[i][prev]; }
        int ans=0;
        if(s[i]=='D'){
            for(int ind=0; ind<prev; ind++){
                if(!vis[ind]){
                    vis[ind]=1;
                    ans=(ans+find(i+1,ind,s))%mod;
                    vis[ind]=0;
                }
            }
        }
        else{
            for(int ind=prev+1; ind<=n; ind++){
                if(!vis[ind]){
                    vis[ind]=1;
                    ans=(ans+find(i+1,ind,s))%mod;
                    vis[ind]=0;
                }
            }
        }
        return dp[i][prev]=ans;
    }
    int numPermsDISequence(string s) {
        n=s.length();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0; i<=n; i++){
            vis[i]=1;
            ans=(ans+find(0,i,s))%mod;
            vis[i]=0;
        }
        return ans;
    }
};

