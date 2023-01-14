// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int memo[1003][1003];
    int ans=0;
    int search(int i, int j, string &s1, string &s2){
        if(i<0 or j<0){ return 0; }
        if(memo[i][j]!=-1){ return memo[i][j]; }
        int val=0;
        if(s1[i]==s2[j]){
            val=1+search(i-1,j-1,s1,s2);
        }
        search(i-1,j,s1,s2);
        search(i,j-1,s1,s2);
        // else{
        // }
        ans=max(ans,val);
        // cout<<i<<' '<<j<<
        return memo[i][j]=val;
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        memset(memo,-1,sizeof(memo));
        // memo[0][0]=1;
        search(n-1,m-1,S1,S2);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends