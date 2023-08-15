typedef pair<int,int> pii;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int src, int tar) {
        if(src==tar){ return 0; }
        map<int,vector<int>> conns;
        unordered_map<int,int> haveDest;
        queue<pii> pq;
        unordered_map<int,int> dist;
        for(int i=0; i<r.size(); i++){
            for(int j=0; j<r[i].size(); j++){
                conns[r[i][j]].push_back(i);
                if(r[i][j]==src){ pq.push({1,i}); dist[i]=1; }
                if(r[i][j]==tar){ haveDest[i]=1; }
            }            
        }
        int ans=INT_MAX;
        while(!pq.empty()){
            int d=pq.front().first, i=pq.front().second; pq.pop();
            if(haveDest[i]==1){ return ans=min(ans,d); }
            for(int &b:r[i]){  // For all the buses that visit this station
                for(int &j:conns[b]){  // For all the stations this bus visits
                    if(dist.count(j)==0 or dist[j]>1+d){
                        pq.push({1+d,j});
                        dist[j]=1+d;
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};