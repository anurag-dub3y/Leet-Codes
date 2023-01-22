class Solution {
public:
    bool isPalin(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void backtrack(vector<vector<string>> &ans, int ind, string s, vector<string> &currArr){
        if(ind==s.length()){ ans.push_back(currArr); return; }
        for(int i=ind; i<s.size(); i++){
            if(isPalin(s,ind,i)){
                currArr.push_back(s.substr(ind,i-ind+1));
                backtrack(ans,i+1,s,currArr);
                currArr.pop_back();
            }
        }
    }    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int ind=0; 
        vector<string> currArr;
        backtrack(ans,ind,s,currArr);
        return ans;
    }
};