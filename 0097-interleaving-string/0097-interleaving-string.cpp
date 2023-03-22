class Solution {
public:
    int dp[103][103][203];
    bool check(int i, int j, int k, string &s1, string &s2, string &s3){
        if(k==s3.length() and i+j==k){ return true; }
        if(dp[i][j][k]!=-1){ return dp[i][j][k]; }
        bool ans=false;
        if(i<s1.length()){
            if(s3[k]==s1[i]){ ans|=check(i+1,j,k+1,s1,s2,s3); }
        }
        if(j<s2.length()){
            if(s3[k]==s2[j]){ ans|=check(i,j+1,k+1,s1,s2,s3); }
        }
        return dp[i][j][k]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.length()+s2.length()!=s3.length()){ return false; }
        return check(0,0,0,s1,s2,s3);
    }
};