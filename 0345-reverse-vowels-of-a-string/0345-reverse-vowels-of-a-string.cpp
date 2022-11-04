class Solution {
public:
    vector<char> vowel = {'a','e','i','o','u','A','E','I','O','U'};
    bool isVowel(char c){
        return count(vowel.begin(),vowel.end(),c)!=0;
    }
    string reverseVowels(string s) {
        vector<char> x;
        for(auto it:s){ if(isVowel(it)){ x.push_back(it); } }
        int j=x.size()-1;
        for(int i=0; i<s.size(); i++){
            if(isVowel(s[i])){
                s[i]=x[j--];
            }
        }
        return s;
    }
};