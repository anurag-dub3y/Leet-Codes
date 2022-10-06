class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return (z == 0) || (z <= x + y && z % __gcd(x, y) == 0) ;
    }
};