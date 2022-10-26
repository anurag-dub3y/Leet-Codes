class Solution {
public:
    long long appealSum(string s) {
        long long ans=0, n=s.length();
        int last[26];
        memset(last,0,sizeof(last));
        for(int i=0; i<s.length(); i++){
            // s[i] contributes to uniqueness of (i-last[s[i]-'a']+1) strings on the left and n-i on the right
            ans+=(i+1-last[s[i]-'a'])*(n-i);
            last[s[i]-'a']=i+1;
        }
        return ans;
    }
};