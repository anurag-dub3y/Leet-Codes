class Solution{
public:
    int m, n;
    int dir[5]={0, 1, 0, -1, 0};
    int DFS(int i, int j, vector<vector<int>>& G){
        if(i<0 || i == m || j < 0 || j == n || G[i][j]==0){ return 0; }
        int val=G[i][j], mn=0;
        G[i][j]=0;
        for(int d=0; d<4; d++){
            int x=i+dir[d], y=j+dir[d+1];
            mn=max(mn,DFS(x,y,G));
        }
        G[i][j]=val;
        return val+mn;
    }
    int getMaximumGold(vector<vector<int>>& G) {
        int ans=0;
        m=G.size(); n=G[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans=max(ans,DFS(i,j,G));
            }
        }
        return ans;
    }
};
