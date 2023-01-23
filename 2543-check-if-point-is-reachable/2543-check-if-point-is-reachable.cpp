class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        return __builtin_popcountll(gcd(targetX, targetY)) == 1;
    }
};