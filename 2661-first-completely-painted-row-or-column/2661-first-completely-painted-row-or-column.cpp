class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> r,c;
        map<int,pair<int,int>> mp;
        int m=mat.size(), n=mat[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0; i<m*n; i++){
            auto [x,y]=mp[arr[i]];
            r[x]++; c[y]++;
            if(r[x]==n or c[y]==m){ return i; }
        }
        return m*n-1;
    }
};