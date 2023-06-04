class Solution {
public:
    void DFS(int i, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[i]=1;
        int n=vis.size();
        for(int k=0; k<n; k++){
            if(isConnected[i][k]==1 && !vis[k]){
                DFS(k, isConnected, vis);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                DFS(i,isConnected,vis);
            }
        }
        return ans;
    }
};