class Solution {
public:
    long long power(long long x, long long y, long long p){
        long long res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0){
            if (y & 1) res = (res*x) % p;
            y = y>>1; 
            x = (x*x) % p;
        }
        return res;
    }
    int monkeyMove(int n) {
        long long p = power(2,n,1000000007);
        return (p-2+1000000007)%1000000007;
    }
};


// In only 2 ways, collision won't happen
// Total moves = 2^n-2