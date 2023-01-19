class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> u;
        ++u[0];
        int ans=0,curr=0;
        for(int i=0; i<nums.size(); i++){
            curr+=nums[i];
            int mod=(curr%k+k)%k;
            ans+=u[mod];
            ++u[mod];
        }
        return ans;
    }
};