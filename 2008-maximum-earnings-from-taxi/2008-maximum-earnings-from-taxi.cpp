class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<long long>> v;
        for(auto r:rides){
            v.push_back({r[1], r[0], r[1]-r[0]+r[2]});
        }
        sort(v.begin(),v.end());
        map<int,long long> dp;
        dp[0]=0;
        for(auto &ride:v){
            long long dollars=prev(dp.upper_bound(ride[1]))->second+ride[2];
            if(dollars>dp.rbegin()->second){
                dp[ride[0]]=dollars;
            }
        }
        return dp.rbegin()->second;
    }
};