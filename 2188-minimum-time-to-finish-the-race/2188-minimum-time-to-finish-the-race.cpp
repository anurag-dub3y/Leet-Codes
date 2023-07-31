typedef long long ll;
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int n) {
        
        const int inf = 0x3f3f3f3f;
        vector<ll> mn(100, inf);
        ll m = 0;
        
        for (auto &v : tires) {
            ll f = v[0], r = v[1];
            
            ll i = 1, c = f , j = f;
            while (1) {
                mn[i] = min(mn[i], c + changeTime);
                m = max(m, i);
                if (j + changeTime <= j * r ) break;
                i++; 
                j *= r;
                c += j;
            }
        }
        
        //for (int i = 1; i <= m; i++) {
        //    cout << i << ' ' << mn[i] << endl;
        //}
        
        ll dp[n + 1];
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i && j <= m; j++) {
                dp[i] = min(dp[i], dp[i - j] + mn[j]);
            }
        }
        
        return dp[n] - changeTime;
        
        
    }
};