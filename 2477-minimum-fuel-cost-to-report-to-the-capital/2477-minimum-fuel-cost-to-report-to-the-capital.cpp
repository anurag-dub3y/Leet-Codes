class Solution {
public:
    long long ans=0;
    int dfs(int i, vector<vector<int>> &g, int par, int seats){
        int pssngr=1;
        for(auto j:g[i]){ if(j!=par){ pssngr+=dfs(j,g,i,seats); } }
        if(i!=0){ ans+=(pssngr/seats)+(pssngr%seats!=0); }
        return pssngr;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int>> g(n);
        for(auto r:roads){
            g[r[0]].push_back(r[1]);
            g[r[1]].push_back(r[0]);
        }
        dfs(0,g,-1,seats);
        return ans;
    }
};