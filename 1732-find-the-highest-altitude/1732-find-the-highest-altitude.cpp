class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0, curr=0;
        for(auto i:gain){
            curr+=i;
            ans=max(ans,curr);
        }
        return ans;
    }
};