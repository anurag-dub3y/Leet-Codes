class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a1="", a2="";
        for(auto i:word1){ a1+=i; }
        for(auto i:word2){ a2+=i; }
        return a1==a2;
    }
};