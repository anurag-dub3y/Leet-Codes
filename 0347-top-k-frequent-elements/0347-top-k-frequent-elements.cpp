class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0; i<nums.size(); i++){ mp[nums[i]]++; }
        vector<pair<int,int>> vp;
        vector<int> v;
        for(auto it=mp.rbegin(); it!=mp.rend(); it++){
            vp.push_back({it->second,it->first});
        }
        sort(vp.begin(),vp.end());
        while(k>0){
            v.push_back(vp.back().second);
            vp.pop_back(); k--;
        }
        return v;
    }
};