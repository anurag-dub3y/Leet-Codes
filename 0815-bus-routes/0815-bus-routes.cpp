typedef pair<int,int> pii;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int src, int tar) {
        if(src==tar){ return 0; }
        unordered_map<int,vector<int>> bus;   // Bueses that visit key station
        queue<pii> pq;
        unordered_set<int> dist={src};
        for(int i=0; i<r.size(); i++){
            for(int j=0; j<r[i].size(); j++){
                bus[r[i][j]].push_back(i);
            }            
        }
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.front().first, i=pq.front().second; pq.pop();
            if(i==tar){ return d; }
            for(int &b:bus[i]){  // For all the buses that visit this station
                for(int &j:r[b]){  // For all the stations this bus visits
                    if(dist.find(j)==dist.end()){
                        pq.push({1+d,j});
                        dist.insert(j);
                    }
                }
                r[b].clear();
            }
        }
        return -1;
    }
};