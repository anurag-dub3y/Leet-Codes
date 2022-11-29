class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1; i<=n; i++){
            for(auto j:wordDict){
                if(i>=j.length()){
                    int ind=i-j.length();
                    string k=s.substr(ind,j.length());
                    if(k==j){ dp[i]=dp[ind]?true:dp[i]; }
                }
            }
        }
        return dp[n];
    }
};