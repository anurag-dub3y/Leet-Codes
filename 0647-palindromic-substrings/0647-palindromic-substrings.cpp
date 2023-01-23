class Solution {
public:
    int count(string &s, int i, int j){
        int ans=0;
        while(i>=0 && j<s.length() and s[i--]==s[j++]){ ans++; }
        return ans;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0; i<s.length(); i++){
            ans+=count(s,i,i);
            ans+=count(s,i,i+1);
        }
        return ans;
    }
};