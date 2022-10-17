class Solution {
public:
    string shortestCommonSupersequence(string p, string q) {
        int m=p.length(), n=q.length();
        vector<vector<string>> dp(m+1,vector<string>(n+1,""));
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(p[i]==q[j]){ dp[i+1][j+1]=p[i]+dp[i][j]; }
                else{
                    dp[i+1][j+1]=(dp[i][j+1].size()>dp[i+1][j].size())?dp[i][j+1]:dp[i+1][j];
                }
            }
        }
        string LCS=dp[m][n];
        reverse(LCS.begin(),LCS.end());
        // cout<<LCS<<endl;
        int x=0, y=0, k=0;
        string ans="";
        while(k<LCS.length()){
            while(x<m && p[x]!=LCS[k]){ ans+=p[x++]; }
            while(y<n && q[y]!=LCS[k]){ ans+=q[y++]; }
            ans+=LCS[k++]; x++; y++;
        }
        while(x<m){ ans+=p[x++]; }
        while(y<n){ ans+=q[y++]; }
        return ans;
    }
};