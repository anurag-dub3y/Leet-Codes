class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        vector<int> vis(arr.size(),0);
        q.push(start);
        while(!q.empty()){
            int x=q.front(); q.pop();
            vis[x]=1;
            if(arr[x]==0){ return true; }
            if(x+arr[x]<arr.size() and !vis[x+arr[x]]){ q.push(x+arr[x]); }
            if(x-arr[x]>=0 and !vis[x-arr[x]]){ q.push(x-arr[x]); }
        }
        return false;
    }
};