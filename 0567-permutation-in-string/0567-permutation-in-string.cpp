class Solution {
public:    
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26,0), b(26,0);
        for(int i=0; i<s1.length(); i++){
            a[s1[i]-'a']++;
        }
        for(int i=0; i<s2.length(); i++){
            b[s2[i]-'a']++;
            if(i>=s1.length()){ b[s2[i-s1.length()]-'a']--; }
            if(a==b){ return true; }
        }
        return false;
    }
};