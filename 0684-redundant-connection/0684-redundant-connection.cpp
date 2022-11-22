class Solution {
public:
    vector<int> parent;
    int find(int x){
        return parent[x]==x?x:find(parent[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=0; i<=n; i++){ parent[i]=i; }
        vector<int> ans(2,0);
        for(auto e:edges){
            int x=find(e[0]), y=find(e[1]);
            if(x!=y){ parent[y]=x; }
            else{ ans[0]=e[0], ans[1]=e[1]; }
        }
        return ans;
    }
};