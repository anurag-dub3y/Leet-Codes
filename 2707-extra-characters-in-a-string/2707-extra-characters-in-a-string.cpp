class Solution {
public:
    vector<int> dp;
    int findExtra(int i, string &s, vector<string>& dictionary){
        if(i==s.length()){ return 0; }
        if(dp[i]!=-1){ return dp[i]; }
        int ans=1+findExtra(i+1,s,dictionary);
        for(auto &j:dictionary){
            if(i+j.length()<=s.length()){
                if(s.substr(i,j.length())==j){ ans=min(ans,findExtra(i+j.length(),s,dictionary)); }
            }
        }    
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        dp=vector<int>(s.length()+1,-1);
        return findExtra(0,s,dictionary);
    }
};