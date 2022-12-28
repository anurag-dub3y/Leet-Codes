class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int ans = accumulate(piles.begin(), piles.end(), 0);
        while(k--) {
            int a = pq.top();
            pq.pop();
            pq.push(a-a/2);
            ans-= a/2;
        }
        return ans;
    }
};