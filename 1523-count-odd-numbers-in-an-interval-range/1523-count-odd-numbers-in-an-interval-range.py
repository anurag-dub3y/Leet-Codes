class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (int)((high-low)/2 + (low%2==1 or high%2==1))
        