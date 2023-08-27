class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1){ return false; }
        unordered_set<int> list(begin(stones),end(stones));
        set<pair<int,int>> vis={{1,1}};
        priority_queue<pair<int,int>> pq;   // ind, jump
        pq.push({1,1});
        while(!pq.empty()){
            auto [i,k]=pq.top(); pq.pop();
            // cout<<"Jumped to "<<i<<" from "<<i-k<<endl;
            if(i==stones.back()){ return true; }
            int j1=i+k-1, j2=i+k, j3=i+k+1;
            if(j1!=i and list.count(j1) and vis.count({j1,k-1})==0){
                vis.insert({j1,k-1});
                pq.push({j1,k-1});
            }
            if(j2!=i and list.count(j2) and vis.count({j2,k})==0){
                vis.insert({j2,k});
                pq.push({j2,k});
            }
            if(j3!=i and list.count(j3) and vis.count({j3,k+1})==0){
                vis.insert({j3,k+1});
                pq.push({j3,k+1});
            }
        }
        return false; 
    }
};