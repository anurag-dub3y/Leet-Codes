class Solution {
public:
    int dp[10][2][2][1<<11];
    int find(int i, bool pad, bool tight, int mask, string &s){
        if(i==s.length()){ return mask!=0; }
        int &ans=dp[i][pad][tight][mask];
        if(ans!=-1){ return ans; }
        ans=0;
        if(pad){
            int mx=tight?s[i]-'0':9;
            for(int j=0; j<=mx; j++){
                ans+=find(i+1,j==0,j==mx and tight,(1<<j),s);
            }
        }
        else{
            int mx=tight?s[i]-'0':9;
            for(int j=0; j<=mx; j++){
                if((mask&(1<<j))==0){
                    ans+=find(i+1,false,tight and j==mx, mask|(1<<j), s);
                }
            }
        }
        return ans;
    }
    int countSpecialNumbers(int n) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        return find(0,1,1,0,s)-1;
    }
};