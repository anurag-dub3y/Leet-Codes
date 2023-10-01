class Solution {
public:
    vector<int> g[30004];
    long long subtree_sum[30004];
    void dfs(int vertex, int par, vector<int>& vals){
        subtree_sum[vertex]+=vals[vertex];
        for(auto child:g[vertex]){
            if(child!=par){
                dfs(child,vertex,vals);
                subtree_sum[vertex]+=subtree_sum[child];
            }
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for(auto &e:edges){
            g[e[0]].push_back(1LL*e[1]);
            g[e[1]].push_back(1LL*e[0]);
        }
        dfs(0LL,-1LL,values);
        int ans=0;
        for(int i=0; i<n; i++){
            if((subtree_sum[i]%k)==0){ ans++; }
        }
        return ans;
    }
};