class Solution {
public:
    using pii=pair<long long,int>;
    int mostBooked(int n, vector<vector<int>>& ms) {
        sort(begin(ms),end(ms));
        vector<int> cnt(n,0);
        priority_queue<int,vector<int>,greater<int>> inds;
        priority_queue<pii,vector<pii>,greater<pii>> meets;
        for(int i=0; i<n; i++){ inds.push(i); }
        for(auto m:ms){
            while(!meets.empty() and m[0]>=meets.top().first){
                inds.push(meets.top().second);
                meets.pop();
            }
            // Finding the availabale room with min index
            if(!inds.empty()){
                meets.push({m[1],inds.top()});
                cnt[inds.top()]++;
                inds.pop();
            }
            else{
                pii t=meets.top(); meets.pop();
                meets.push({t.first+m[1]-m[0],t.second});
                cnt[t.second]++;
            }
        }
        for(int i=0; i<n; i++){
            if(cnt[i]==*max_element(begin(cnt),end(cnt))){ return i; }
        }
        return 0;
    }
};