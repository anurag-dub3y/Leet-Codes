class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.size()==0){ return 0;}
        map<int,unordered_set<int>> g;
        for(auto &e:roads){
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ans=max(ans,(int)(g[i].size()+g[j].size()-g[i].count(j)));
            }
        }
        return ans;
    }
};


// 0 1 2 3 4 5 6
        //   7