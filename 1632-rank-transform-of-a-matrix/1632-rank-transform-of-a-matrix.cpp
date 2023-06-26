// class Solution {
// public:
// //     using pii=pair<int,int>
// //     void make_set(pii v) {
// //         parent[v] = v;
// //     }
    
// //     int find_set(int v) {
// //         if (v == parent[v])
// //             return v;
// //         return find_set(parent[v]);
// //     }
    
// //     void union_sets(int a, int b) {
// //         a = find_set(a);
// //         b = find_set(b);
// //         if (a != b)
// //             parent[b] = a;
// //     }
//     using vii=vector<int>;
//     vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
//         vector<vii> vp;
//         int m=mat.size(), n=mat[0].size();
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 vp.push_back({mat[i][j],i,j});
//             }
//         }
//         sort(begin(vp),end(vp));
//         vector<vector<int>> ans(m,vector<int>(n,0));
//         vii rows(m,0), cols(n,0);
//         vector<vii> rMx(m), cMx(n);
//         for(int i=0; i<m; i++){
//             rMx[i]={-1,INT_MIN};
//         }
//         for(int j=0; j<n; j++){
//             cMx[j]={-1,INT_MIN};
//         }
//         for(int k=0; k<vp.size(); k++){
//             int v=vp[k][0], i=vp[k][1], j=vp[k][2];
//             if(v==rMx[i][1] or v==cMx[j][1]){
//                 ans[i][j]=max(ans[i][rMx[i][0]],ans[cMx[j][0]][j]);
//             }
//             if(v==rMx[i][1]){
//                 ans[i][j]=ans[i][rMx[i][0]];
//             }
//             if(v==cMx[j][1]){
//                 ans[i][j]=max(ans[i][j],ans[cMx[j][0]][j]); 
//             }
//             if(v!=rMx[i][1] and v!=cMx[j][1]){
//                 ans[i][j]=1+max(rows[i],cols[j]);
//             }
//             if(v>rMx[i][1]){ rMx[i]={j,v}; }
//             if(v>cMx[j][1]){ cMx[j]={i,v}; }
//             rows[i]=max(rows[i],ans[i][j]);
//             cols[j]=max(cols[j],ans[i][j]);
//         }
//         // cout<<'\n';
//         return ans;
//     }
// };
class DSU {
    public:
         DSU(int n): p_(n, -1) {}
         int find(int x) {
           return p_[x] == -1 ? x : p_[x] = find(p_[x]);
         }  
         void merge(int x, int y) {
           x = find(x), y = find(y);
           if (x != y) p_[x] = y;    
         }
    private:
      vector<int> p_;
};
 
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        map<int, vector<pair<int, int>>> mp; // val -> {positions}
        for (int y = 0; y < m; ++y){
            for (int x = 0; x < n; ++x){
                mp[matrix[y][x]].emplace_back(x, y);
            }
        }
        vector<int> rx(n), ry(m);
        for (const auto& [val, ps]: mp) {
          DSU dsu(n + m);
          vector<vector<pair<int, int>>> cc(n + m); // val -> {positions}
          
            // By merging xth row and yth column ranks, now their rank will be the max of the ranks observed while
            // merging them
            for (const auto& [x, y]: ps) dsu.merge(x, y + n);
            for (const auto& [x, y]: ps) cc[dsu.find(x)].emplace_back(x, y);      
            for (const auto& ps: cc) {
                int rank = 1;
                for (const auto& [x, y]: ps)
                    rank = max(rank, max(rx[x], ry[y]) + 1);
                for (const auto& [x, y]: ps)
                    rx[x] = ry[y] = ans[y][x] = rank;   
            }      
        }
        return ans;
  }
};