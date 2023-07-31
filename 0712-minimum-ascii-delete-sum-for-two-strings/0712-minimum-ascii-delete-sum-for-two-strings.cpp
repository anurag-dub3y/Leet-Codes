class Solution {
public:
    int dp[1001][1001];
    int find(int i, int j, string &s1, string &s2){
        int &val=dp[i][j];
        if(val!=-1){ return val; }
        if(i==s1.length() and j==s2.length()){ return val=0; }
        else if(i==s1.length()){ int ans=0; while(j<s2.length()){ ans+=s2[j++]; } return val=ans; }
        else if(j==s2.length()){ int ans=0; while(i<s1.length()){ ans+=s1[i++]; } return val=ans; }
        
        if(s1[i]==s2[j]){ return val=find(i+1,j+1,s1,s2); }
        return val=min({s1[i]+find(i+1,j,s1,s2),s2[j]+find(i,j+1,s1,s2),s1[i]+s2[j]+find(i+1,j+1,s1,s2)});
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,s1,s2);
    }
};