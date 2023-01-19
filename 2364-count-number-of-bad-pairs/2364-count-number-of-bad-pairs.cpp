class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> u;
        long long ans=0;
        for(int i=0; i<nums.size(); i++){
            int good=u[nums[i]-i];
            ans+=i-good;
            ++u[nums[i]-i];
        }
        return ans;
    }
};