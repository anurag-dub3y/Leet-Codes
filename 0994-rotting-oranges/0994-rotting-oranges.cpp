class Solution {
public:
    // #define vector<int> vii
    int d[5]={-1,0,1,0,-1};
    int m, n;
    int orangesRotting(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        // priority_queue<vii,vector<vii>,greater<vii>> pq;
        queue<vector<int>> pq;
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){ pq.push({i,j}); }
                else if(grid[i][j]==1){ cnt++; }
            }
        }
        int t=0;
        while(!pq.empty() and cnt>0){
            t++;
            int sz=pq.size();
            while(sz--){
                auto t=pq.front(); pq.pop();
                for(int r=0; r<4; r++){
                    int x=t[0]+d[r], y=t[1]+d[r+1];
                    if(x>=0 and y>=0 and x<m and y<n and grid[x][y]==1){
                        cnt--;
                        grid[x][y]=2;
                        pq.push({x,y});
                    }
                }
            }
        }
        if(cnt){ return -1; }
        return t;
    }
};