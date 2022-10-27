class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<=10){ return {}; }
        unordered_map<string,int> u;
        for(int i=0; i+9<s.length(); i++){
            string curr=s.substr(i,10);
            ++u[curr];
        }
        vector<string> ans;
        for(auto i:u){
            if(i.second>1){ ans.push_back(i.first); }
        }
        return ans;
    }
};