class Solution {
public:
    vector<int> vis;
    vector<vector<int>> dp, g;
    int n;
    void dfs(int i, string &s, int &mx, int &foundCycle){
        if(vis[i]==0){ foundCycle=1; return; }
        if(vis[i]==1){ return; }
        vis[i]=0;
        for(auto &r:g[i]){
            dfs(r,s,mx,foundCycle);
            for(int c=0; c<26; c++){
                dp[i][c]=max(dp[i][c],dp[r][c]);
            }
        }
        vis[i]=1;
        dp[i][s[i]-'a']++;
    }
    int largestPathValue(string &colors, vector<vector<int>>& edges) {
        n=colors.size();
        dp=vector<vector<int>>(n,vector<int>(26,0));
        g=vector<vector<int>>(n);
        for(auto e:edges){ g[e[0]].push_back(e[1]); }
        vis.resize(n,-1);
        int ans=0, cycle=0;
        for(int i=0; i<n; i++){
            dfs(i,colors,ans,cycle);
            ans=max(ans,(*max_element(begin(dp[i]),end(dp[i]))));
            if(cycle){ return -1; }
        }
        return ans;
    }
};