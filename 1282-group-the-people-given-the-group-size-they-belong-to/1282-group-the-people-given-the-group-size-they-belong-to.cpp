class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<pair<int,int>> vp;
        for(int i=0; i<gs.size(); i++){
            vp.push_back({gs[i],i});
        }
        sort(begin(vp),end(vp));
        vector<vector<int>> ans;
        vector<int> tmp;
        for(int i=0; i<vp.size(); i++){
            tmp.push_back(vp[i].second);
            if(tmp.size()==vp[i].first){
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};