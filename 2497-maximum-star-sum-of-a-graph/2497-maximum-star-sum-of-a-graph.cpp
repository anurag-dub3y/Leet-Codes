class Solution {
public:
    int k;
    vector<int> g[100005];
    vector<int> vals;
    int vis[100005];
    int dfs(int i){
        int curr=INT_MIN;
        vis[i]=1;
        priority_queue<int> pq;
        int k_dash=k;
        for(auto &j:g[i]){
            if(vals[j]>0){ pq.push(vals[j]); }
            if(!vis[j]){ curr=max(curr,dfs(j)); }
        }
        int sum=vals[i];
        while(k_dash>0 and !pq.empty()){ sum+=pq.top(); pq.pop(); k_dash--; }
        return max(curr,sum);
    }
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        if(edges.size()==0){ return *max_element(begin(vals),end(vals)); }
        this->vals=vals;
        this->k=k;
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans=INT_MIN;
        for(int i=0; i<vals.size(); i++){
            if(!vis[i]){ ans=max(ans,dfs(i)); }
        }
        return ans;
    }
};