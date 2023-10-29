class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0, n=nums.size();
        for(int i=0; i<n; i++){
            for(int len=1; i+len<=n; len++){
                set<int> s(nums.begin()+i,nums.begin()+i+len);
                int sz=s.size();
                ans+=sz*sz;
            }
        }
        return ans;
    }
};