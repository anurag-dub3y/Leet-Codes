class Solution {
public:
    int countOdds(int low, int high) {
        return (high-low)/2 + (low%2==1 or high%2==1);
    }
};