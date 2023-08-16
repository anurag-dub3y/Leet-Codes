class Solution {
public:
    vector<int> g[51];
    vector<int> vis;
    int dfs(int i, int &cnt){
        vis[i]=1;
        int ans=1;
        cnt+=g[i].size();
        for(auto &j:g[i]){
            if(!vis[j]){ ans+=dfs(j,cnt); }
        }
        return ans;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vis.resize(n+1,0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int bridges=0;
                int nodes=dfs(i,bridges);
                bridges>>=1;
                // cout<<nodes<<' '<<bridges<<endl;
                if(bridges==nodes*(nodes-1)/2){ ans++; }
            }
        }
        return ans;
    }
};