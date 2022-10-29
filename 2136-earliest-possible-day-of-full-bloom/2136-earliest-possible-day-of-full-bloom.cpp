class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        for(int i=0; i<plantTime.size(); i++){ v.push_back({plantTime[i],growTime[i]}); }
        sort(v.begin(),v.end(),[&](const pair<int,int> a, const pair<int,int> b){
            return a.second>b.second;
            // if(a.first!=b.first){ return a.first>b.first; }
        });
        int currD=-1, mxDays=0;
        for(int i=0; i<v.size(); i++){
            currD+=v[i].first;  mxDays=max(mxDays,currD+v[i].second+1);          
        }
        return mxDays;
    }
};
