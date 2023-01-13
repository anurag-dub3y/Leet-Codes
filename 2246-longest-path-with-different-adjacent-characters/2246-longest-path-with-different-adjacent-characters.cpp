class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        if(n==1){ return 1; }
        vector<vector<int>> g(n,vector<int>());
        for(int i=1; i<parent.size(); i++){
            g[parent[i]].push_back(i);
        }
        int ans=0;
        dfs(0,s,g,ans);
        return ans;
    }
    int dfs(int i, string &s, vector<vector<int>> &g, int &ans){
        int mx1=0, mx2=0;        
        for(auto u:g[i]){
            int len=dfs(u,s,g,ans);
            if(s[u]==s[i]){ continue; }
            if(len>mx1){ mx2=mx1; mx1=len; }
            else{ mx2=max(mx2,len); }
        }
        ans=max(ans,1+mx1+mx2);
        return 1+mx1;
    }
};


// Either i is the pivot point 
// Or we have to return 