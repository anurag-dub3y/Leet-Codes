class Solution {
public:
    struct cell {
        int d, x, y;
        cell(int a, int b, int c) : d (a), x (b), y (c){}
        bool operator< (const cell &k) const {return d > k.d;}
    };
    int dir[5]={-1,0,1,0,-1};
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<cell> pq;
        int n=grid.size(), maxD=0;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        pq.push(cell(grid[0][0],0,0));
        vis[0][0]=1;
        while(true){
            auto r=pq.top();
            pq.pop();
            maxD=max(maxD,r.d);
            int i=r.x, j=r.y;
            if(i==n-1 && j==n-1){ return maxD; }
            for(int k=1; k<=4; k++){
                int newI=i+dir[k-1], newJ=j+dir[k];
                if(newI>=0 && newI<n && newJ>=0 && newJ<n && !vis[newI][newJ]){
                    pq.push(cell(grid[newI][newJ],newI,newJ));
                    vis[newI][newJ]=1;
                }
            }
        }
        return -1;
    }
};