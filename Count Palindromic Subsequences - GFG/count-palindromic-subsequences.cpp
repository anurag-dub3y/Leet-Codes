//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    const int mod=1e9+7;
    long long int countPS(string s){
        int n = s.length();
        long long int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=n; i++){
            dp[i][i]=1;
        }
        for(int len=2; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int k=i+len-1;
                if(s[i]==s[k]){
                    // anurag
                    // anura
                    // -> anur nura
                    dp[i][k]=(mod+dp[i+1][k-1]+dp[i][k-1]+dp[i+1][k]+1-dp[i+1][k-1])%mod;
                }
                else{
                    dp[i][k]=(mod+dp[i][k-1]+dp[i+1][k]-dp[i+1][k-1])%mod;
                }
            }
        }
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends