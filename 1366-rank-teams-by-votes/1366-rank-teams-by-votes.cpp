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
        sort(begin(vp),end(vp),[&](pair<vector<int>,char> &a, pair<vector<int>,char> &b){
            if(a.first==b.first){ return a.second<b.second; }
            for(int i=0; i<a.first.size(); i++){
                if(a.first[i]!=b.first[i]){ return a.first[i]<b.first[i]; }
            }
            return false;
        });
        sort(begin(vp),end(vp));
        string ans="";
        for(auto &[cnt,ch]:vp){ 
            ans+=ch; 
            // for(auto &i:cnt){ cout<<i<<' '; } cout<<endl;
        }
        return ans;
    }
};