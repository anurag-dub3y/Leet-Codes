class Solution{
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        auto validate=[&](int i,int j){
            if(i<0||i>=m-1||j<0||j>=n-1) return false;
            return true;
        };
        map<pair<int,int>,int> mp;
        vector<long long> ans(5,0LL);
        for(auto c:coordinates){
            if(validate(c[0]-1,c[1]-1)){ mp[{c[0]-1,c[1]-1}]++; }
            if(validate(c[0]-1,c[1])){ mp[{c[0]-1,c[1]}]++; }
            if(validate(c[0],c[1]-1)){ mp[{c[0],c[1]-1}]++; }
            if(validate(c[0],c[1])){ mp[{c[0],c[1]}]++; }
        }
        for(auto &i:mp){ ans[i.second]++; }
        ans[0]=1LL*(m-1)*(n-1)-ans[1]-ans[2]-ans[3]-ans[4];
        return ans;
    }
};