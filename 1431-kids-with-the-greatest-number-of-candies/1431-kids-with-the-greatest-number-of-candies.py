class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=*max_element(begin(candies),end(candies));
        vector<bool> ans(candies.size());
        for(int i=0; i<candies.size(); i++){
            ans[i]=candies[i]+extraCandies>=mx;
        }
        return ans;
    }
};