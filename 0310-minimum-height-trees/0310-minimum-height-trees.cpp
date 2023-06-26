class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){ return {0}; }
        vector<vector<int>> g(n);
        vector<int> deg(n,0);
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            deg[e[0]]++; deg[e[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){ if(deg[i]==1){ q.push(i); } }
        vector<int> ans;
        while(!q.empty()){
            vector<int> curr;
            int sz=q.size();
            while(sz--){
                int f=q.front(); q.pop();
                curr.push_back(f);
                for(auto j:g[f]){
                    if(--deg[j]==1){
                        q.push(j);
                    }
                }
            }
            ans=curr;
        }
        return ans;
    }
};