class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){ return nums[0]==1; }
        int g=gcd(nums[0],nums[1]);
        for(int i=2; i<n; i++){
            g=gcd(g,nums[i]);
        }
        return g==1;
    }
};