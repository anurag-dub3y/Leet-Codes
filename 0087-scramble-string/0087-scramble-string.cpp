class Solution {
public:
    unordered_map<string,bool> m;
    bool isScramble(string s1, string s2) {
        if(s1==s2){ return true; }
        if(m.find(s1+'_'+s2)!=m.end()){
            return m[s1+'_'+s2];
        }
        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++) {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++) {
            if(count[i]!=0){ return false; }
        }
        
        bool flag=false;
        
        for(int i=1; i<=len-1; i++) {
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))){
                flag=true; break;
            }
            if(isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i))){
                flag=true; break;
            }
        }
        return m[s1+'_'+s2]=flag;
    }
};