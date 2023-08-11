class Solution {
public:
    map<string,multiset<string>> g;
    vector<string> ans;
    void dfs(string s){
        while(g[s].size()){
            string dest=*g[s].begin();
            g[s].erase(g[s].begin());
            dfs(dest);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &s:tickets){ g[s[0]].insert(s[1]); }
        dfs("JFK");
        reverse(begin(ans),end(ans));
        return ans;
    }
};