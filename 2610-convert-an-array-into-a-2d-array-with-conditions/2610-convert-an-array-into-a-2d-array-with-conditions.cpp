class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){ ++m[i]; }
        vector<vector<int>> ans;
        int cnt=m.size();
        while(cnt>0){
            vector<int> temp;
            for(auto &i:m){
                if(i.second==0){ continue; }
                temp.push_back(i.first);
                i.second--;
                if(i.second==0){ cnt--; }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};