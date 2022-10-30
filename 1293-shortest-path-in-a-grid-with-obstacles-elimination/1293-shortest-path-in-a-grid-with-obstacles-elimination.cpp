class Solution {
public:
    vector<vector<int>> vis;
    int m, n;
    int minD=1e9;
    int d[5]={-1,0,1,0,-1};
    bool isValid(int i, int j){
        if(i<0 or i>=m or j<0 or j>=n){ return false; }
        return true;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        m=grid.size(), n=grid[0].size();
        vis.resize(m,vector<int>(n,-1));
        queue<vector<int>> q;
        q.push({0,0,k,0});
        while(!q.empty()){
            vector<int> top=q.front();
            q.pop();
            int i=top[0], j=top[1], rem=top[2], dist=top[3];
            if(i==m-1 && j==n-1){ return dist; }
            if(grid[i][j]==1){ rem--; }
            if(rem<0){ continue; }
            if(vis[i][j]!=-1 && vis[i][j]>=rem){ continue; }
            vis[i][j]=rem;
            for(int r=0; r<4; r++){
                int newI=i+d[r], newJ=j+d[r+1];
                if(isValid(newI,newJ)){ q.push({newI,newJ,rem,dist+1});  }
            }
        }
        return -1;
    }
};
