int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
typedef array<int,3> vii;
class Solution {
public:
    int minimumTime(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size();
        if(g[0][1]>1 and g[1][0]>1){ return -1; }
        auto cmp=[&](vii a, vii b){
            return a[0]>b[0];
        };
        int ans;
        priority_queue<vii,vector<vii>,decltype(cmp)> pq(cmp);
        pq.push({0,0,0});
        vector<vector<int>> vis(m,vector<int>(n,0));
        while(!pq.empty()){
            auto [t,i,j]=pq.top(); pq.pop();
            if(i==m-1 and j==n-1){ ans=t; break; }
            if(vis[i][j]){ continue; }
            vis[i][j]=1;
            for(int r=0; r<4; r++){
                int x=i+dx[r], y=j+dy[r];
                if (x < 0 || x >= m || y < 0 || y >= n) { continue; }
                 int wait = (g[x][y] - t) % 2 == 0;
                pq.push({max(g[x][y] + wait, t + 1), x, y});
            }
        }
        return ans;
    }
};