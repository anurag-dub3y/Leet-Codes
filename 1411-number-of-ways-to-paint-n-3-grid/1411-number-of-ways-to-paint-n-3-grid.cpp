class Solution {
public:
    int numOfWays(int n) {
        long long mod=1e9+7, c2 = 6, c3 = 6, tmp = 0;
        for(int i=2; i<=n; i++){
            tmp = c3;
            c3 = (2*c3)%mod + (2*c2)%mod;
            c2 = (2*tmp)%mod + (3*c2)%mod;
            c3 = c3%mod;
            c2 = c2%mod;
        }
        return (c3+c2)%mod;
    }
};