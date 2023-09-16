class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // pq.top().first = cost of reaching to (pq.top().second/100,pq.top().second%100)
        
        int dirs[5] = {-1, 0, 1, 0, -1};
        
        pq.emplace(0,0);
                
        while(!pq.empty()){
            int minCost = pq.top().first;
            int x = pq.top().second/100;
            int y = pq.top().second%100;
            
            pq.pop();
            
            if (x==m-1 && y==n-1) return minCost;
            
            if(minCost>=cost[x][y]){ continue; }
            cost[x][y]=minCost;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i], ny = y + dirs[i+1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n){ continue; }
                int n_effort = max(minCost, abs(heights[x][y]-heights[nx][ny]));
                pq.emplace(n_effort, nx * 100 + ny);
            }
        }
        
        return -1;
    }
};