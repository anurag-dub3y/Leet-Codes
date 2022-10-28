class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int dp[26]={0}, currLen=0;
        for(int i=0; i<p.length(); i++){
            if(i>0 && (p[i-1]-'a'+1)%26==(p[i]-'a')){ currLen++; }
            else{ currLen=1; }
            dp[p[i]-'a']=max(dp[p[i]-'a'],currLen);
        }
        return accumulate(dp,dp+26,0);
    }
};