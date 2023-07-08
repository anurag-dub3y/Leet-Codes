class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> x={0};
        for(auto i:arr){
            x.push_back(i^x.back());
        }
        vector<int> ans(queries.size());
        for(int i=0; i<queries.size(); i++){
            ans[i]=x[queries[i][1]+1]^x[queries[i][0]];
        }
        return ans;
    }
};