class Solution {
public:
    vector<vector<int>> vis;
    int m,n;
    int dj[4]={0,1,0,-1}, di[4]={-1,0,1,0};
    bool dfs(int i, int j, int cnt, int pari, int parj, vector<vector<char>>& g){
        vis[i][j]=cnt;
        bool ans=false;
        for(int r=0; r<4; r++){
            int ni=i+di[r], nj=j+dj[r];
            if(ni<m && nj<n && ni>=0 and nj>=0 and g[ni][nj]==g[i][j]){
                if(!vis[ni][nj]){
                    ans|=dfs(ni,nj,cnt+1,pari,parj,g);
                }
                else if(cnt-vis[ni][nj]>=3){ 
                    // cout<<cnt+1<<endl;
                    return true; 
                }
            }
        }
        return ans;
    }
    bool containsCycle(vector<vector<char>>& g) {
        m=g.size(), n=g[0].size();
        vis.resize(m,vector<int>(n,0));
        bool ans=false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    vis[i][j]=1;
                    for(int r=0; r<4; r++){
                        int ni=i+di[r], nj=j+dj[r];
                        if(ni<m && nj<n && ni>=0 && nj>=0 && g[ni][nj]==g[i][j]){
                            ans|=dfs(ni,nj,2,i,j,g);
                            // if(ans){ return true; }
                        }
                    }
                }
            }
        }
        return ans;
    }
};