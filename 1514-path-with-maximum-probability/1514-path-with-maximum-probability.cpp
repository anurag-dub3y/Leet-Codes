class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& suxes, int start, int end) {
        double f=1.00000001;
        vector<vector<pair<int,double>>> g(n);
        for(int i=0; i<e.size(); i++){
            // cout<<e[i][0]<<' '<<e[i][1]<<' '<<suxes[i]<<endl;
            g[e[i][0]].push_back({e[i][1],f*suxes[i]});
            g[e[i][1]].push_back({e[i][0],f*suxes[i]});
        }
        vector<double> dist(n,0.0);
        vector<int> vis(n,0);
        priority_queue<pair<double,int>> pq;
        pq.push({f,start}); 
        dist[start]=f; 
        // vis[start]=1;
        while(!pq.empty()){
            pair<double,int> t=pq.top(); pq.pop(); 
            double p=f*t.first; int i=t.second;
            // cout<<i<<' '<<p<<'\n';
            // if(i==end){ return p; }
            if(!vis[i]){
                vis[i]=1;
                for(auto r:g[i]){
                    int j=r.first; double curr=r.second;
                    if(dist[j]<f*p*curr){ 
                        double newP=f*p*curr;
                        // cout<<newP<<endl;
                        pq.push({newP,j}); 
                        dist[j]=f*p*curr; 
                    }
                }
            }
        }
        return dist[end];
    }
};