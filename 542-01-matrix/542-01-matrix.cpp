class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){ continue; }
                int up=m+n, left=m+n;
                if(i>=1){ up=mat[i-1][j]; }
                if(j>=1){ left=mat[i][j-1]; }
                mat[i][j]=min(up,left)+1;
            }
        }
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(mat[i][j]==0){ continue; }
                int bottom=m+n, right=m+n;
                if(i<m-1){ bottom=mat[i+1][j]; }
                if(j<n-1){ right=mat[i][j+1]; }
                mat[i][j]=min(mat[i][j],min(bottom,right)+1);
            }
        }
        return mat;
    }
};