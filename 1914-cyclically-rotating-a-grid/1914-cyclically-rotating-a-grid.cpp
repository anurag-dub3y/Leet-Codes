class Solution{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0; i<min(m,n)/2; i++){
            int z=2*(m+n-2);
            z-=8*i;
            for(int t=0;t<k%z;t++){
                int p=grid[i][i];
                int q=grid[m-i-1][i];
                int r=grid[i][n-i-1];
                int s=grid[m-i-1][n-i-1];
                for(int h=i;h<n-i-1;h++) grid[i][h]=grid[i][h+1];
                for(int h=m-i-1;h>i;h--) grid[h][i]=grid[h-1][i];
                
                for(int h=n-i-1;h>i;h--) grid[m-i-1][h]=grid[m-i-1][h-1];
                
                for(int h=i;h<m-i-1;h++) grid[h][n-i-1]=grid[h+1][n-i-1];
                
                grid[i+1][i]=p;
                grid[m-i-2][n-i-1]=s;
                grid[m-i-1][i+1]=q;
                grid[i][n-i-2]=r;
                    
            }
        }
        return grid;
    }
};