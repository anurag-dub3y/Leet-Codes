class Solution {
public:
    int miceAndCheese(vector<int>& r1, vector<int>& r2, int k) {
        int n=r1.size();
        vector<pair<int,int>> vp;
        for(int i=0; i<n; i++){ vp.push_back({r1[i],r2[i]}); }
        sort(begin(vp),end(vp),[&](const pair<int,int> &a, const pair<int,int> &b){
            return a.first-a.second>b.first-b.second;
        });
        int ans=0;
        for(int i=0; i<n; i++){
            if(i<k){ ans+=vp[i].first; }
            else{ ans+=vp[i].second; }
        }
        return ans;
    }
};