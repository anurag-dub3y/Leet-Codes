// // class Solution {
// // public:
// //     int m, n;
// //     int minimumVisitedCells(vector<vector<int>>& grid) {
// //         m=grid.size(); n=grid[0].size();
// //         vector<vector<int>> distance(m,(vector<int>(n,INT_MAX)));
// //         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
// //         pq.push({1,0,0});
// //         distance[0][0]=1;
// //         while(!pq.empty()){
// //             auto v=pq.top(); pq.pop();
// //             int d=v[0], i=v[1], j=v[2];
// //             if(i==m-1 and j==n-1){ return d; }
// //             if(grid[i][j]==0){ continue; }
// //             for(int x=i+1; x<=min(m-1,grid[i][j]+i); x++){
// //                 if(distance[x][j]>d+1){
// //                    distance[x][j]=d+1;
// //                    pq.push({d+1, x, j});
// //                    if(x==m-1 and j==n-1){ return d+1; }
// //                 }
// //             }
// //             for(int y=j+1; y<=min(n-1,grid[i][j]+j); y++){
// //                 if(distance[i][y]>d+1) {
// //                     distance[i][y]=d+1;
// //                     pq.push({d+1,i,y});
// //                     if(i==m-1 and y==n-1){ return d+1; }
// //                 }
// //             }
// //         }
// //         return -1;
// //     }
// // };
// class Solution {
// public:

// struct Node {
//     int x; 
//     int y;
//     Node(int i, int j) : x(i), y(j) {}
//     friend bool operator<(const Node& n1, const Node& n2) {
//         return n1.x < n2.x;
//     }
// };


// int minimumVisitedCells(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
//         for(int j=0; j<=n; ++j) {
//             dp[0][j] = -1;
//         }
//         for(int i=0; i<=m; ++i) {
//             dp[i][0] = -1;
//         }

//         std::vector<priority_queue<pair<int, Node>, vector<pair<int, Node>>, greater<pair<int, Node>>>> vq_h;
//         std::vector<priority_queue<pair<int, Node>, vector<pair<int, Node>>, greater<pair<int, Node>>>> vq_v;
//         for(int i=0; i<m; ++i) {
//             priority_queue<pair<int, Node>, vector<pair<int, Node>>, greater<pair<int, Node>>> q;
//             vq_h.push_back(q);
//         }
//         for(int i=0; i<n; ++i) {
//             priority_queue<pair<int, Node>, vector<pair<int, Node>>, greater<pair<int, Node>>> q;
//             vq_v.push_back(q);
//         }

//         for(int i=1; i<=m; ++i) {
//             for(int j=1; j<=n; ++j) {
//                 if(i==1 && j==1) {
//                     dp[i][j] =  1;
//                     vq_h[i-1].push({1, Node(i, j)});
//                     vq_v[j-1].push({1, Node(i, j)});
//                 } else {
//                     dp[i][j] = INT_MAX;

//                     int res = INT_MAX;
//                     // Check horizontal
//                     while(!vq_h[i-1].empty()) {
//                         auto top = vq_h[i-1].top();
//                         auto x = top.second.x;
//                         auto y = top.second.y;
//                         auto dist = grid[x-1][y-1]+y;
//                         if(dist<j) {
//                             vq_h[i-1].pop();
//                         } else {
//                             res = std::min(res, top.first);
//                             break;
//                         }
//                     }

//                     // Check vertical
//                     while(!vq_v[j-1].empty()) {
//                         auto top = vq_v[j-1].top();
//                         auto x = top.second.x;
//                         auto y = top.second.y;
//                         auto dist = grid[x-1][y-1]+x;
//                         if(dist<i) {
//                             vq_v[j-1].pop();
//                         } else {
//                             res = std::min(res, top.first);
//                             break;
//                         }
//                     }

//                     dp[i][j] = std::min(dp[i][j], res);
//                     if(dp[i][j]==INT_MAX) { 
//                         dp[i][j] = -1;
//                     } else {
//                         dp[i][j]++;
//                         vq_h[i-1].push({dp[i][j], Node(i,j)});
//                         vq_v[j-1].push({dp[i][j], Node(i,j)});
//                     }
//                 }
//             }
//         }
        
//         return dp[m][n];
//     }

// };
class Solution {
public:
    struct node {
        int cnt, dis;
    };
    struct compare {
        bool operator()(const node &a, const node &b) {
            return a.cnt > b.cnt;
        }
    };

    priority_queue<node, vector<node>, compare> vq[100000];
    priority_queue<node, vector<node>, compare> hq;
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i, j, minv = -1;
        int ans = -1;
        for (i = 0; i< n ; ++i) {
            while(!hq.empty()) hq.pop();
            for (j = 0; j <m; ++j) {
                while(!hq.empty() && hq.top().dis < j) hq.pop();
                while(!vq[j].empty() && vq[j].top().dis < i) vq[j].pop();
                if(!hq.empty() && minv > hq.top().cnt) minv = hq.top().cnt;
                if(!vq[j].empty() && minv > vq[j].top().cnt) minv = vq[j].top().cnt;
                hq.push({minv + 1, j + grid[i][j]});
                vq[j].push({minv + 1, i + grid[i][j]});                
                if(i == n - 1 && j == m - 1) ans = minv + 1;
                minv = 1000000;
            }
            minv = 1000000;            
        }

        if(ans == 1000001) ans = -1;
        else ans += 1;
        return ans;
    }
};