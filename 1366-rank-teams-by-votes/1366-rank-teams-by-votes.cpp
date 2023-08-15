class Solution {
public:
    string rankTeams(vector<string>& votes) {
        map<char,vector<int>> m;
        for(auto &s:votes){
            for(int i=0; i<s.length(); i++){
                m[s[i]].push_back(i);
            }
        }
        vector<pair<vector<int>,char>> vp;
        for(auto &[ch,cnt]:m){ sort(begin(cnt),end(cnt)); vp.push_back({cnt,ch}); }
        sort(begin(vp),end(vp));
        string ans="";
        for(auto &[cnt,ch]:vp){ 
            ans+=ch; 
            // for(auto &i:cnt){ cout<<i<<' '; } cout<<endl;
        }
        return ans;
    }
};