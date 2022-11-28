class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        map<int,int> mp;
        vector<int> z, w;
        for(auto m:matches){
            if(mp.find(m[0])==mp.end()){ mp.insert({m[0],0}); }
            ++mp[m[1]];
        }
        for(auto it:mp){
            if(it.second==0){ z.push_back(it.first); }
            else if(it.second==1){ w.push_back(it.first); }
        }
        return {z,w};
    }
};