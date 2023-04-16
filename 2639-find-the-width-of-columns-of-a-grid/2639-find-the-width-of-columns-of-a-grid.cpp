class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size();
        vector<int> ans(n,0);
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                string s=to_string(g[i][j]);
                ans[j]=max(ans[j],(int)s.length());
            }
        }
        return ans;
    }
};