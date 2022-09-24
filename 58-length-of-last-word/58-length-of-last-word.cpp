class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int len;
        while(ss>>word){
            len=word.length();
        }
        return len;
    }
};