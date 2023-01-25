class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> v1(n,1e7), v2(n,1e7);
        pq.push({0,node1});
        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            v1[x.second]=x.first;
            if(edges[x.second]==-1){ continue; }
            int dest=edges[x.second];
            if(v1[dest]>1+x.first){ pq.push({1+x.first,dest}); }
        }
        pq.push({0,node2});
        while(!pq.empty()){
            auto x=pq.top(); pq.pop();
            v2[x.second]=x.first;
            if(edges[x.second]==-1){ continue; }
            int dest=edges[x.second];
            if(v2[dest]>1+x.first){ pq.push({1+x.first,dest}); }
        }
        int ans=1e7, ind=-1;
        for(int i=0; i<n; i++){
            // cout<<v1[i]<<' '<<v2[i]<<endl;
            if(max(v1[i],v2[i])<ans){ ans=max(v1[i],v2[i]); ind=i; }
        }
        return ind;
    }
};