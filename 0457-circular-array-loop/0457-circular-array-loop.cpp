class Solution {
public:
    vector<int> graph;
    bool dfs(vector<int> &visit,int node,int sign){
        int next=(node+graph[node]+graph.size())%(graph.size());
        if(next==node||graph[node]*sign<0){ return false; }
        if(visit[node]==1){ return true; }
        visit[node]=1;
        return dfs(visit,next,sign);
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        graph=nums;
        for(int i=0; i<n; i++) {
            vector<int> visit(n,0);
            int sign=graph[i]>0?1:-1;
            if(dfs(visit,i,sign)){ return true; }
        }
        return false;
    }
};