class Solution {
public:
    unordered_map<string,vector<string>> m;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(auto i:strs){
            string x=i;
            sort(x.begin(),x.end());
            m[x].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
    }
};