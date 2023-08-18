class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& p) {
        int n=p.size();
        vector<int> dist(n,1e6);
        dist[0]=0;
        vector<int> g[n];
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(0);
        int d=0;
        dist[0]=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int u=q.front(); q.pop();
                // cout<<u<<' ';
                for(auto &v:g[u]){
                    if(dist[v]>2*(1+d)){
                        q.push(v);
                        dist[v]=2*(1+d);
                    }
                }
            }
            d++;
        }
        int ans=0;
        for(int i=1; i<n; i++){
            if(p[i]>=dist[i]){ ans=max(ans,dist[i]); }
            else{
                if(dist[i]%p[i]==0){
                    ans=max(ans,2*dist[i]-p[i]);
                }
                else{
                    ans=max(ans,2*dist[i]-dist[i]%p[i]);    
                }
            }
        }
        // cout<<endl;
        return ans+1;
    }
};