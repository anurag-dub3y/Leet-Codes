class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto i:nums){ pq.push(i); }
        long long score=0;
        while(k--){
            int x=pq.top(); pq.pop();
            score+=x;
            int f=x%3?1:0;
            pq.push(x/3+f);
        }
        return score;
    }
};