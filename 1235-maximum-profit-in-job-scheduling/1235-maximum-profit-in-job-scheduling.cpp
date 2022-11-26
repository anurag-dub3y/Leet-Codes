class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        unordered_map<int,int> u;
        for(int i=0; i<startTime.size(); i++){
            v.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(v.begin(),v.end());        // Job that ends first appears first
        map<int,int> dp;                // Storing max profit of upto time dp.first
        dp[0]=0;                        // Initially profit=0
        for(auto &job:v){
            // If we choose current job, the profit we can get equals to profit from this job plus the max profit we
            // would have gotten from time t < startTime of this job (t should be just less than startTime)
            // If we ignore it then we simply won't insert the value attainable from above
            int profitIfChosen = prev(dp.upper_bound(job[1]))->second + job[2];         
            if(profitIfChosen > dp.rbegin()->second){
                dp[job[0]]=profitIfChosen;
            }
        }
        // Return max profit at time t = last value pushed into the map
        return dp.rbegin()->second;
    }
};