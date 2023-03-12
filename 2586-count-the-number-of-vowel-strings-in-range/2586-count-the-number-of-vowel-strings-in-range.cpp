class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        auto isVowel=[&](const string &s){
            string v="aeiou";
            if(count(v.begin(),v.end(),s[0])!=0 and count(v.begin(),v.end(),s.back())!=0){ return true; }
            return false;
        };        
        int ans=0;
        for(int i=left; i<=right; i++){
            if(isVowel(words[i])){ ans++; }
        }
        return ans;
    }
};