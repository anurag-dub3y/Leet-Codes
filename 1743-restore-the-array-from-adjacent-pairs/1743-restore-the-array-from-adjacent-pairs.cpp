class Solution {
public:
    // vector<int> g[200005];
    vector<int> g[200005];
    void dfs(int i, int par, vector<int> &ans){
        ans.push_back(i-100000);
        for(auto &j:g[i]){
            if(j!=par){ dfs(j,i,ans); return; }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto &e:adjacentPairs){
            g[e[0]+100000].push_back(e[1]+100000);
            g[e[1]+100000].push_back(e[0]+100000);
        }
        vector<int> ans;
        for(int i=0; i<200005; i++){
            // if(g[i].size()!=0){ cout<<i-100000<<' '; for(auto &j:g[i]){ cout<<j-100000<<' '; } cout<<endl; }
            if(g[i].size()==1){ dfs(i,-1,ans); return ans; }
        }
        return {};
    }
};