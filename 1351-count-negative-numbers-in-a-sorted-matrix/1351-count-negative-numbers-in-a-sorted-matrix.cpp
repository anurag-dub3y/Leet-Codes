class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(auto &it:grid){
            reverse(begin(it),end(it));
            ans+=(lower_bound(begin(it),end(it),0)-it.begin());
        }
        return ans;
    }
};