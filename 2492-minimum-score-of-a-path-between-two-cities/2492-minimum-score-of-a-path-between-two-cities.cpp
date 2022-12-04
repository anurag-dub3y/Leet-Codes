class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> g[n+1];
        vector<int> vis(n+1,0); 
        for(auto r:roads){
            g[r[0]].push_back({r[1],r[2]});
            g[r[1]].push_back({r[0],r[2]});
        }
        queue<int> q;
        q.push(1); vis[1]=1;
        while(!q.empty()){
            int x=q.front(); q.pop();
            vis[x]=1;
            for(auto r:g[x]){
                if(!vis[r.first]){
                    q.push(r.first);
                }
            }
        }
        int mnVal=INT_MAX;
        for(int i=0; i<roads.size(); i++){
            if(vis[roads[i][0]] and vis[roads[i][1]]){
                mnVal=min(mnVal,roads[i][2]);
            }
        }
        return mnVal;
    }
};