class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        for(auto i:word){
            if(i>='A' and i<='Z'){ ++cnt; }
        }
        return cnt==word.length() or cnt==0 or (cnt==1 and word[0]>='A' and word[0]<='Z');
    }
};