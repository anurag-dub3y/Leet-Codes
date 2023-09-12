class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> tmp;
        int m=grid.size(), n=grid[0].size();
        auto rotate=[&](vector<int> &arr, int d){
            vector<int> tmp=arr;
            for(int i=0; i<arr.size(); i++){
                tmp[i]=arr[(i+d+arr.size())%arr.size()];
            }
            arr=tmp;
        };
        for(int i=0; i<min(m,n)/2; i++){
            int x=i, y=i;
            vector<int> tmp2;
            while(y < n - i){ tmp2.push_back(grid[x][y++]); }
            // cout<<"ok"<<endl;
            y--; x++;
            while(x < m - i){ tmp2.push_back(grid[x++][y]); }
            // cout<<"ok"<<endl;
            x--; y--;
            while(y >= i){ tmp2.push_back(grid[x][y--]); }
            // cout<<"ok"<<endl;
            y++;  x--;
            while(x > i){ tmp2.push_back(grid[x--][y]); }
            // cout<<"ok"<<endl;
            // for(auto &r:tmp2){ cout<<r<<' '; } cout<<endl;
            rotate(tmp2,k);
            x=i, y=i; int j=0;
            while(y < n - i){ grid[x][y++]=tmp2[j++]; }
            y--; x++;
            while(x < m - i){ grid[x++][y]=tmp2[j++]; }
            x--; y--;
            while(y >= i){ grid[x][y--]=tmp2[j++]; }
            y++; x--;
            while(x > i){ grid[x--][y]=tmp2[j++]; }
        }
        return grid;
    }
};
