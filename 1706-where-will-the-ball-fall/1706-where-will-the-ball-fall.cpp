class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> ans(n);
        for(int j=0; j<n; j++) {
            int x=j, y;
            for(int i=0; i<m; ++i){
                y=x+grid[i][x];
                if(y<0 or y>=n || grid[i][y]!=grid[i][x]){ x=-1; break; }
                x=y;
            }
            ans[j]=x;
        }
        return ans;
    }
};