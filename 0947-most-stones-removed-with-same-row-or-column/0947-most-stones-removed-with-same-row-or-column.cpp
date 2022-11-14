class Solution {
public:
    vector<int> g[1001];
    const int K=1001;
    vector<int> vis;
    int dfs(int i){
        vis[i]=1;
        int ans=1;
        for(auto j:g[i]){
            if(!vis[j]){ ans+=dfs(j); }
        }
        return ans;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vis.resize(1001,0);
        for(int i=0; i<n; i++){
            int p=stones[i][0], q=stones[i][1];
            for(int j=i+1; j<n; j++){
                int l=stones[j][0], r=stones[j][1];
                if(p==l or q==r){
                    g[i].push_back(j); g[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0; i<1001; i++){
            if(!vis[i]){
                int x=dfs(i);
                ans+=(x>0)?x-1:0;
            }
        }
        return ans;
    }
};