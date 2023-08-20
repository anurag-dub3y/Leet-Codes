class Solution {
public:
    int n;
    int find(int i, vector<vector<int>>& offers, vector<int>& dp) {
        if(i >= n){ return 0; }
        int &ans=dp[i];
        if(ans!=-1){ return ans; }
        
        ans=find(i + 1, offers, dp);
        
        int v1 = 0;
        int next = n;
        int curr = offers[i][1];
        int low = i + 1, high = n - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int curr = offers[mid][0];
            if (curr > offers[i][1]) {
                next = mid;
                high = mid - 1;
            } 
            else { low = mid + 1; }
        }

        v1 += offers[i][2] + find(next, offers, dp);

        return ans = max(v1, ans);
    }
    
    int maximizeTheProfit(int n1, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end());
        n = offers.size();
        vector<int> dp(n, -1);
        return find(0, offers, dp);
    }
};