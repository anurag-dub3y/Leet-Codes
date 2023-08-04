class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.length()+1,0);
        for(int i=s.length()-1; i>=0; i--){
            dp[i]=1+dp[i+1];
            for(auto &j:dictionary){
                if(i+j.length()<=s.length()){
                    if(s.substr(i,j.length())==j){ dp[i]=min(dp[i],dp[i+j.length()]); }
                }
            }
        }
        return dp[0];
    }
};