class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 10000001));
        queue<pair<int,int>> q;
        q.push({0,0});
        dp[0][0] = 0;
        while(!q.empty()){
            auto curr = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int x = dx[i] + curr.first, y = dy[i] + curr.second;
                if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] + dp[curr.first][curr.second] < dp[x][y]){
                    dp[x][y] = grid[x][y] + dp[curr.first][curr.second];
                    q.push({x, y});
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};