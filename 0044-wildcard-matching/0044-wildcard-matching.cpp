class Solution {
public:
    int dp[2001][2001];
    int check(int i, int j, string &s, string &p){
        if(i==s.length() and j==p.length()){ return true; }
        else if(i==s.length()){
            return p[j]=='*' and check(i,j+1,s,p);
        }
        if(j==p.length()){ return false; }
        int &ans=dp[i][j];
        if(ans!=-1){ return ans; }
        ans=0;
        if(s[i]==p[j] or p[j]=='?'){
            ans|=check(i+1,j+1,s,p); 
        }
        else if(p[j]=='*'){
            ans|=check(i+1,j,s,p);
            ans|=check(i,j+1,s,p);
            ans|=check(i+1,j+1,s,p);
        }
        return ans;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return check(0,0,s,p);
    }
};