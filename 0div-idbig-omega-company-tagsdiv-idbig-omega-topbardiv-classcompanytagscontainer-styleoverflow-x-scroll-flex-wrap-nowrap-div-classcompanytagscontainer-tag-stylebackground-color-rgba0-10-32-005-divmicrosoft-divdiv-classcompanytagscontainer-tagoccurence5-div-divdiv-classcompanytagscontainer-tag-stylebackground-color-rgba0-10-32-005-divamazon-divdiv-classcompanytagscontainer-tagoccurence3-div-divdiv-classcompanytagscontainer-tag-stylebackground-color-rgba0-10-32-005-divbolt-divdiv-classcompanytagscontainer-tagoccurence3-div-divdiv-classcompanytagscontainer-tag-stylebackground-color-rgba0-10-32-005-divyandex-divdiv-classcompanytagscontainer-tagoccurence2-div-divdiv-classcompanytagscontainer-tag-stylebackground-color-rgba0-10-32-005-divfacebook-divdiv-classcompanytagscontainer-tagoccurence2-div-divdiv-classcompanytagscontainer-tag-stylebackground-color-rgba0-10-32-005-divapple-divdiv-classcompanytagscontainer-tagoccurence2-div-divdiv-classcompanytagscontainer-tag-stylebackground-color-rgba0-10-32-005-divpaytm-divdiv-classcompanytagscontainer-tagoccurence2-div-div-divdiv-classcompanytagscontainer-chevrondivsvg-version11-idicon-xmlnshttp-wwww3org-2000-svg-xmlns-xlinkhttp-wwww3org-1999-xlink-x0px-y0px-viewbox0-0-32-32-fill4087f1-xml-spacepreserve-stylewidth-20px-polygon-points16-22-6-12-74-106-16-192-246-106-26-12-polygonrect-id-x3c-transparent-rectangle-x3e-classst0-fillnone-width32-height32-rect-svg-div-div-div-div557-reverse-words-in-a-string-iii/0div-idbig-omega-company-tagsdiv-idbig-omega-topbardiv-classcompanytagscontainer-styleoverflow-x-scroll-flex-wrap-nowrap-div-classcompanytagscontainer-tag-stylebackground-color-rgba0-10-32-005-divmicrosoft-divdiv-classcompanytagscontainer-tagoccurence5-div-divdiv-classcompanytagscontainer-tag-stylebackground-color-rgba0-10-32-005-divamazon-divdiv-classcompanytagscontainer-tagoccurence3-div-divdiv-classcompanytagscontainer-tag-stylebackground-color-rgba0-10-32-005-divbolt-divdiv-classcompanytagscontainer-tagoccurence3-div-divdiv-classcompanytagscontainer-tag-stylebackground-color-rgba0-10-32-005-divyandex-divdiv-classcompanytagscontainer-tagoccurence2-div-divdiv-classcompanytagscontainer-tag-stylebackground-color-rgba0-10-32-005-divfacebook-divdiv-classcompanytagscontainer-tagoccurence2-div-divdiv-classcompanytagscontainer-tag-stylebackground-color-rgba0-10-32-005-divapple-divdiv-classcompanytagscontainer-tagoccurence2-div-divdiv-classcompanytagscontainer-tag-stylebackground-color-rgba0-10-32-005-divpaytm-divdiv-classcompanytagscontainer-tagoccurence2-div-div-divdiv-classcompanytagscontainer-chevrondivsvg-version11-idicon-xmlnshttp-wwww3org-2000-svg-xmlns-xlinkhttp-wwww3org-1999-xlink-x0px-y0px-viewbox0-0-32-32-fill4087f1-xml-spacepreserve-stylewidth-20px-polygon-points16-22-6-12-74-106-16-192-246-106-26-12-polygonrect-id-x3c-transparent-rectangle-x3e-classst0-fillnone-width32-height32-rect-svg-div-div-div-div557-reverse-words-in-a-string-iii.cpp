class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        stringstream ss(s);
        string word;
        int i=0;
        while(ss>>word){
            reverse(word.begin(),word.end());
            if(i!=0){ ans+=' '; }
            ans+=word;
            i++;
        }
        return ans;
    }
};