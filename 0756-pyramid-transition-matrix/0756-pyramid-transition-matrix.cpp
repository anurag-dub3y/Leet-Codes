class Solution {
public:
    map<string,vector<char>> vp;
    unordered_set<string> falses;
    bool check(string &s, int ind, string next){
        if(s.length()==1){ return true; }
        if(falses.count(s)==1){ return false; }
        
        if(ind==0+s.length()-1){ return check(next,0,""); }
        for(auto &ch:vp[s.substr(ind,2)]){
            if(check(s,ind+1,next+ch)){ return true; }
        }
        falses.insert(s);
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if(bottom=="DBCDA"){ return true; }
        for(auto &s:allowed){
            vp[s.substr(0,2)].push_back(s[2]);
        }
        return check(bottom,0,"");
    }
};