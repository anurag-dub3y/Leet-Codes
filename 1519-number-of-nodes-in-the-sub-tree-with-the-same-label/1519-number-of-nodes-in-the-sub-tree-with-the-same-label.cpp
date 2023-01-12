class Solution {
public:
    vector<vector<int>> g;
    void dfs(int i, string &s, vector<int>& freq, vector<int>& ans){
        if(ans[i]!=0){ return; }
        freq[s[i]-'a']=1;
        ans[i]=1;
        for(auto u:g[i]){
            vector<int> newF(26,0);
            dfs(u,s,newF,ans);
            for(int r=0; r<26; r++){ freq[r]+=newF[r]; }
        }
        ans[i]=freq[s[i]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        g.resize(n+1);
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int> freq(26,0), ans(n,0);
        dfs(0,labels,freq,ans);
        return ans;
    }
};