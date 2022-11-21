class Solution {
public:
    vector<vector<int>> vis;
    int m, n;
    bool check(int i, int j, vector<vector<char>> &maze){
        return i>=0 and i<m and j>=0 and j<n and !vis[i][j] and maze[i][j]!='+';
    }
    int d[5]={-1,0,1,0,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m=maze.size(), n=maze[0].size();
        vis.resize(m,vector<int>(n,0));
        auto cmp = [](vector<int> left, vector<int> right){ return(left[0])>(right[0]); };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
        pq.push({0,entrance[0],entrance[1]});
        vis[entrance[0]][entrance[1]]=1;
        while(!pq.empty()){
            vector<int> v=pq.top(); pq.pop();
            if((v[1]==0 or v[2]==0 or v[1]==m-1 or v[2]==n-1) and v[0]!=0){ return v[0]; }
            for(int k=0; k<4; k++){
                if(check(v[1]+d[k],v[2]+d[k+1],maze)){ 
                    pq.push({v[0]+1,v[1]+d[k],v[2]+d[k+1]}); 
                    vis[v[1]+d[k]][v[2]+d[k+1]]=1;
                }
            }
        }
        return -1;
    }
};