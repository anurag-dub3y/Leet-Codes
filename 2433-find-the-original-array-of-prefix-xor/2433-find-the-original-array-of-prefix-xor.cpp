class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans; 
        for (int i = 0; i < pref.size(); ++i) {
            if (i == 0) ans.push_back(pref[i]); 
            else ans.push_back(pref[i-1] ^ pref[i]); 
        }
        return ans; 
    }
};