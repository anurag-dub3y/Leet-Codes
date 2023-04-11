class Solution {
public:
    string removeStars(string s) {
        int n=s.length();
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]!='*'){ ans+=s[i]; }
            else{ ans.pop_back(); }
        }
        return ans;
    }
};