class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(begin(logs),end(logs),[&](vector<int> &v1, vector<int> &v2){
            return v1[1]<v2[1];    
        });
        vector<pair<int,int>> qs;
        for(int i=0; i<queries.size(); i++){
            qs.push_back({queries[i],i});
        }
        sort(begin(qs),end(qs));
        deque<pair<int,int>> dq;
        map<int,int> mp;
        vector<int> ans(queries.size());
        int i=0;
        for(auto &[time,ind]:qs){
            while(i<logs.size() and logs[i][1]<=time){
                dq.push_back({logs[i][1],logs[i][0]});
                mp[logs[i][0]]++;
                i++;
            }
            while(!dq.empty() and dq.front().first<time-x){
                mp[dq.front().second]--;
                if(mp[dq.front().second]==0){
                    mp.erase(dq.front().second);
                }
                dq.pop_front();
            }
            ans[ind]=n-mp.size();
        }
        return ans;
    }
};