class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<int>> g;
    int m, n;
    int di[4]={-1,0,1,0}, dj[4]={0,1,0,-1};
    bool isValid(int &x, int &y){
        return x>=0 and y>=0 and x<m and y<n and !vis[x][y] and g[x][y]==0;
    }
    void makeOne(int &i, int &j){
        vis[i][j]=1; g[i][j]=1;
        for(int r=0; r<4; r++){
            int x=i+di[r], y=j+dj[r];
            if(isValid(x,y)){ makeOne(x,y); }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        g=grid;
        m=grid.size(); n=grid[0].size();
        vis.resize(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 or i==m-1 or j==0 or j==n-1){
                    if(isValid(i,j)){ makeOne(i,j); }
                }
            }
        }
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isValid(i,j)){ ans++; makeOne(i,j); }
            }
        }
        return ans;
    }
};