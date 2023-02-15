//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int water_flow(vector<vector<int>> &h,int m,int n){
        // int m=h.size(), n=h[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));
        for(int i=0; i<m; i++){
            dfs(h,pac,i,0);
            dfs(h,atl,i,n-1);
        }
        for(int j=0; j<n; j++){
            dfs(h,pac,0,j);
            dfs(h,atl,m-1,j);
        }
        int ans=0;
        for (int i=0; i<m; i++) for(int j=0; j<n; j++){
            if(pac[i][j] && atl[i][j]){
                ans++;
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j){
        vis[i][j]=true;
        if(i-1>=0 && !vis[i-1][j] && h[i-1][j]>=h[i][j]){
            dfs(h,vis,i-1,j);
        }
        if(i+1<h.size() && !vis[i+1][j] && h[i+1][j]>=h[i][j]){
            dfs(h,vis,i+1,j);
        }
        if(j-1>=0 && !vis[i][j-1] && h[i][j-1]>=h[i][j]){
            dfs(h,vis,i,j-1);
        }
        if(j+1<h[0].size() && !vis[i][j+1] && h[i][j+1]>=h[i][j]){
            dfs(h,vis,i,j+1);
        }
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends