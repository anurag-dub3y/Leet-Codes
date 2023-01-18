class Solution {
public:
    vector<vector<int>> dp;
    int search(int i, vector<vector<int>>& events, int k){
        if(i>=events.size() or k<=0){ return 0; }
        if(dp[i][k]!=-1){ return dp[i][k]; }
        vector<int> temp = {events[i][1],INT_MAX,INT_MAX};
        int nextInd = upper_bound(events.begin()+i+1, events.end(), temp)-events.begin();
        return dp[i][k]=max(search(i+1,events,k),events[i][2]+search(nextInd,events,k-1));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        events.push_back({0,0,0});
        sort(events.begin(),events.end());
        int n=events.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        return search(0,events,k);
    }
};