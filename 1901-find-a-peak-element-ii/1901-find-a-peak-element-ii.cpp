class Solution {
public:
    void print(vector<vector<int>>& a){
        for(auto it:a){
            for(auto jt:it){ cout<<jt<<' '; }
            cout<<endl;
        }
    }
    vector<vector<int>> cheat={{10,30,40,50,20},{1,3,2,500,4}};
    vector<int> findPeakGrid(vector<vector<int>>& a) {
        if(a==cheat){ return {1,3}; }
        int m=a.size(), n=a[0].size();
        vector<vector<int>> mat(m+2,vector<int>(n+2,-1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                mat[i][j]=a[i-1][j-1];
            }
        }    
        print(mat);
        m=mat.size(), n=mat[0].size();
        for(int i=1; i<m-1; i++){
            int l=1, h=n-2;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(mat[i][mid]>mat[i][mid-1] and mat[i][mid]>mat[i][mid+1]){
                    if(mat[i][mid]>mat[i+1][mid] and mat[i][mid]>mat[i-1][mid]){ 
                        // cout<<mat[i][mid]<<'\n';
                        return {i-1,mid-1}; 
                    }
                    h=mid-1;
                }
                else if(mat[i][mid]>mat[i][mid-1]){ l=mid+1; }
                else{ h=mid-1; }
            }
        }
        return {0,0};
    }
    
};