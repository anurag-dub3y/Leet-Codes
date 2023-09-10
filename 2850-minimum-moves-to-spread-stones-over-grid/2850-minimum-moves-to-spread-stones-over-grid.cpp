class Solution {
public:
    int find(vector<pair<int,int>>& v1, vector<pair<int,int>>& v2, int i){
        if(i>=v1.size()){ return 0; }
        int ans=INT_MAX, f=0;
        for(int j=0 ; j<v2.size() ; j++){
            int x=abs(v1[i].first-v2[j].first)+abs(v1[i].second-v2[j].second);
            int a=v2[j].first, b=v2[j].second;
            v2[j]={1e8,1e8};  
            f=x+find(v1,v2,i+1);  
            ans=min(ans, f);   
            v2[j]={a,b}; 
        }
        return ans;
    }

    int minimumMoves(vector<vector<int>>& grid) {
        if(grid[0][0]==9 or grid[0][2]==9 or grid[2][0]==9 or grid[2][2]==9){ return 18; }
        if(grid[0][1]==9 or grid[1][0]==9 or grid[1][2]==9 or grid[2][1]==9){ return 15; }
        if(grid[1][1]==9){ return 12;  }
        int n=grid.size(), m=grid[0].size();
        vector<pair<int,int>> v1,v2;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){ v1.push_back({i,j}); }
                else if(grid[i][j]>1){  
                    int x=grid[i][j]-1;
                    while(x--){ v2.push_back({i,j}); }
                }
            }
        }
        int ans=find(v1,v2,0);
        return ans;
    }
};