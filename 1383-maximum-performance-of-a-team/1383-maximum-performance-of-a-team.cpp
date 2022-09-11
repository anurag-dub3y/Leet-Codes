class Solution {
public:
    #define pii pair<int,int>
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> v(n);
        for (int i = 0; i < n; ++i)
            v[i] = {efficiency[i], speed[i]};
        sort(rbegin(v), rend(v));
        long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq; //min heap
        for(auto& x: v){
            int e=x.first, s=x.second;
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % (int)(1e9+7);
    }
};