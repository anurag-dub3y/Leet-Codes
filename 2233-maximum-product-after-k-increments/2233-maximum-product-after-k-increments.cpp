class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:nums){ pq.push(i); }
        while(k--){
            int r=pq.top(); pq.pop(); pq.push(r+1);
        }
        long long ans=1LL, mod=1e9+7;
        while(!pq.empty()){
            ans=(ans*pq.top())%mod;
            pq.pop();
        }
        return ans;
    }
};