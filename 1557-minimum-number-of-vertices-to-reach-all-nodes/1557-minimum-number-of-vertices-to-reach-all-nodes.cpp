class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> yes(n,0), ans;
        for(auto e:edges){
            yes[e[1]]=1;
        }
        for(int i=0; i<n; i++){ if(!yes[i]){ ans.push_back(i); } }
        return ans;
    }
};