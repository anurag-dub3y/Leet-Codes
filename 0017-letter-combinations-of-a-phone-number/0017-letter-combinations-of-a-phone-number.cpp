class Solution {
public:
    void backtrack(vector<string>& s, string curr, int ind, string digits){
        if(ind==digits.length()){ s.push_back(curr); return; }
        if(digits[ind]=='2'){
            backtrack(s,curr+'a',ind+1,digits);
            backtrack(s,curr+'b',ind+1,digits);
            backtrack(s,curr+'c',ind+1,digits);
        }
        else if(digits[ind]=='3'){
            backtrack(s,curr+'d',ind+1,digits);
            backtrack(s,curr+'e',ind+1,digits);
            backtrack(s,curr+'f',ind+1,digits);
        }
        else if(digits[ind]=='4'){
            backtrack(s,curr+'g',ind+1,digits);
            backtrack(s,curr+'h',ind+1,digits);
            backtrack(s,curr+'i',ind+1,digits);
        }
        else if(digits[ind]=='5'){
            backtrack(s,curr+'j',ind+1,digits);
            backtrack(s,curr+'k',ind+1,digits);
            backtrack(s,curr+'l',ind+1,digits);
        }
        else if(digits[ind]=='6'){
            backtrack(s,curr+'m',ind+1,digits);
            backtrack(s,curr+'n',ind+1,digits);
            backtrack(s,curr+'o',ind+1,digits);
        }
        else if(digits[ind]=='7'){
            backtrack(s,curr+'p',ind+1,digits);
            backtrack(s,curr+'q',ind+1,digits);
            backtrack(s,curr+'r',ind+1,digits);
            backtrack(s,curr+'s',ind+1,digits);
        }
        else if(digits[ind]=='8'){
            backtrack(s,curr+'t',ind+1,digits);
            backtrack(s,curr+'u',ind+1,digits);
            backtrack(s,curr+'v',ind+1,digits);
        }
        else if(digits[ind]=='9'){
            backtrack(s,curr+'w',ind+1,digits);
            backtrack(s,curr+'x',ind+1,digits);
            backtrack(s,curr+'y',ind+1,digits);
            backtrack(s,curr+'z',ind+1,digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> s;
        if(digits.length()==0){ return s; }
        string curr="";
        backtrack(s,curr,0,digits);
        return s;
    }
};