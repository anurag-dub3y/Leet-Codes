class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][2][2][2][10];
    int find(int i, bool tight1, bool tight2, bool pad, int prev, string &low, string &high) {
        if (i == low.length()) { return 1; }
        int &ans=dp[i][tight1][tight2][pad][prev];
        if(ans!=-1){ return ans; }
        ans=0;
        if (pad && low[i] == '0') {
            int end= tight2? high[i]-'0':9;
            for (int j = 0; j <= end; j++) {
                // if(j!=high[i]-'0'){ cout<<"Not tight2"<<endl; }
                ans = (ans + find(i + 1, j==0, tight2 and j == end, j==0, j, low, high)) % mod;
            }
        } else {
            int st = tight1 ? low[i] - '0' : 0;
            int end = tight2 ? high[i] - '0' : 9;
            // if(!tight2){ cout<<"Not tight2 "<<st<<' '<<end<<' '<<prev<<endl; }
            for (int j = st; j <= end; j++) {
                if (abs(prev - j) == 1 or pad) {
                    ans = (ans + find(i + 1, tight1 && j == low[i] - '0', tight2 && j == high[i] - '0', false, j, low, high)) % mod;
                }
            }
        }
        
        return ans;
    }
    
    int countSteppingNumbers(string &low, string &high) {
        memset(dp,-1,sizeof(dp));
        int diff = high.length() - low.length();
        string tmp = string(diff, '0') + low;
        return find(0, 1, 1, 1, 0, tmp, high);
    }
};
