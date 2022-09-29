class Solution {
public:
    #define pii pair<int,int>
    #define f first
    #define s second
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        vector<int> ans;
        for(auto i:arr){ pq.push({abs(x-i),i}); }
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().s);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};