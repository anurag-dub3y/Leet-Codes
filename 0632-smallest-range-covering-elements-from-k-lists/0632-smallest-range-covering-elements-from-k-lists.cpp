class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n; i++){
            for(int j=0; j<nums[i].size(); j++){
                if(j>0 and nums[i][j]==nums[i][j-1]){ continue; }
                pq.push({nums[i][j],i});
            }
        }
        vector<int> count(n,0);
        set<pair<int,int>> st;
        int ans1=-1e5, ans2=1e5;
        while(!pq.empty()){
            auto top=pq.top(); pq.pop();
            count[top.second]++;
            int mn=top.first;
            st.insert(top);
            while(*min_element(count.begin(),count.end())>0){
                // for(auto it:count){ cout<<it<<' '; }
                // cout<<endl;
                auto it=*st.rbegin(); st.erase(it);
                int mx=it.first;
                // cout<<mn<<' '<<mx<<endl;
                if(mx-mn<=ans2-ans1){
                    ans1=mn; ans2=mx;
                }
                count[it.second]--;
            }
        }
        return {ans1,ans2};
    }
};