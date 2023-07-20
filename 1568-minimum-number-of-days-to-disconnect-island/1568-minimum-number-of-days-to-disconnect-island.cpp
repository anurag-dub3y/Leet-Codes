// class UF{
// public:
//     int rank, parent;
//     UF(int n){
//         rank.resize(n,1);
//         for(int i=0; i<n; i++){ parent.push_back(i); }
//     }
//     int find(int n){
//         if(n==parent[n]){ return n; }
//         return parent[n]=find(parent[n]);
//     }
//     void merge(int a, int b){
//         a=find(a); b=find(b);
//         if(rank[a]>rank[b]){ par[b]=a; rank[a]+=rank[b]; }
//         else{ rank[b]+=rank[a]; par[a]=b; }
//     }
// };

void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited){
    if(i>=grid.size() || j>=grid[0].size() || j<0 || i<0) return;
    if(!visited[i][j] && grid[i][j]){
        visited[i][j]=1;
        dfs(grid, i-1, j, visited);
        dfs(grid, i+1, j, visited);
        dfs(grid, i, j-1, visited);
        dfs(grid, i, j+1, visited);
    }
    return;
}

int cc(vector<vector<int>> &grid, vector<vector<int>> &visited){
    int count=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0; j<grid[i].size() ;j++){
            if(!visited[i][j] && grid[i][j]){
                count++;
                dfs(grid, i, j, visited);
            }
        }
    }
    return count;
    
}
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int c=0;
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[i].size(); j++) if(grid[i][j]) c++;
        if(c==1) return 1;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
        int x = cc(grid, visited);
        if(x>1 || x==0) return 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(),0));
                if(grid[i][j] && !visited[i][j]){
                    grid[i][j] = 0;
                    x = cc(grid,visited);
                    if(x > 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};