class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start, end;
        for(auto i:flowers){ start.push_back(i[0]); end.push_back(i[1]); }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int> ans;
        for(auto i:persons){
            int h=upper_bound(start.begin(),start.end(),i)-start.begin(), l=lower_bound(end.begin(),end.end(),i)-end.begin();
            ans.push_back(h-l);
        }
        return ans;
    }
};