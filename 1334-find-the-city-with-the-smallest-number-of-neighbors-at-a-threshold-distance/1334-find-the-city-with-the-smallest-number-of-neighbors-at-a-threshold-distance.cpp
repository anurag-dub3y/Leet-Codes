class Solution {
public:
    vector<pair<int,int>> g[101];
    int dj(int src, int n, int threshold){
        vector<int> d(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> ms;
        ms.push({0,src});
        d[src]=0;
        while(!ms.empty()){
            auto [dist,u]=ms.top(); ms.pop();
            for(auto &[v,wt]:g[u]){
                if(dist+wt<d[v]){
                    ms.push({dist+wt,v});
                    d[v]=dist+wt;
                }
            }
        }
        // cout<<src<<"    ";
        int cnt=0;
        for(auto &i:d){ /*cout<<i<<' ';*/ if(i<=threshold){ cnt++; } }
        // cout<<endl;
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto &e:edges){
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        int city=0, mn=n+1;
        for(int i=0; i<n; i++){
            int d=dj(i,n,distanceThreshold);
            if(d<=mn){ mn=d; city=i; }
        }
        // cout<<endl;
        return city;
    }
};