class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,0);
        unordered_set<int> u(days.begin(),days.end());
        for(int i=1; i<366; i++){
            if(u.find(i)==u.end()){ dp[i]=dp[i-1]; }
            else{
                dp[i]=min({dp[i-1]+costs[0],dp[max(i-7,0)]+costs[1],dp[max(i-30,0)]+costs[2]});
            }
        }
        return dp[365];
    }
};