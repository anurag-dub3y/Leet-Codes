class Solution {
public:
    vector<int> g[101];
    bool dfs(int src, int dest, vector<int> &vis){
        if(src==dest){ return true; }
        vis[src]=1;
        for(auto &j:g[src]){
            if(!vis[j] and dfs(j,dest,vis)){ return true; }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& reqd, vector<vector<int>>& qrs) {
        vector<bool> ans(qrs.size());
        for(auto &r:reqd){ g[r[0]].push_back(r[1]); }
        for(int i=0; i<qrs.size(); i++){
            vector<int> vis(n,0);
            ans[i]=dfs(qrs[i][0],qrs[i][1],vis);
        }
        return ans;
    }
};