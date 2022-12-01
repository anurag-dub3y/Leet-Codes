class Solution {
public:
    bool halvesAreAlike(string s) {
        vector<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
        int vow1=0, vow2=0;
        for(int i=0; i<s.length()/2; i++){
            if(count(vowels.begin(),vowels.end(),s[i])){ vow1++; }
        }
        for(int i=s.length()/2; i<s.length(); i++){
            if(count(vowels.begin(),vowels.end(),s[i])){ vow2++; }
        }
        return vow1==vow2;
    }
};