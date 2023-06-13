class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mp;
        int ans=0;
        for(auto it:grid){ mp[it]++; }
        for(int j=0; j<grid[0].size(); j++){
            vector<int> col;
            for(int i=0; i<grid.size(); i++){
                col.push_back(grid[i][j]);
            }
            ans+=mp[col];
        }
        return ans;
    }
};