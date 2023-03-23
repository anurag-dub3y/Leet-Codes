class Solution {
public:
    int vis[100005]={0};
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){ return -1; }
        vector<vector<int>> arr(n);
        for(auto v : connections) {
            arr[v[0]].push_back(v[1]);
            arr[v[1]].push_back(v[0]);
        }
        int conn=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){ conn++; dfs(i,arr); }
        }
        return conn-1;
    }
    void dfs(int n, vector<vector<int>>& arr){
        vis[n]=1; 
        for(int i=0; i<arr[n].size(); i++){
            if(!vis[arr[n][i]]) dfs(arr[n][i],arr);
        }
    }
};