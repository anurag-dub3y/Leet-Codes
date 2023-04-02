class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(auto s:spells){
            long long div=success%s==0?success/s:(success/s)+1;
            int len=potions.size()-(lower_bound(potions.begin(),potions.end(),div)-potions.begin());
            ans.push_back(len);
        }
        return ans;
    }
};