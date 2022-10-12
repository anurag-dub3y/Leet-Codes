class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int GCD=numsDivide[0];
        for(auto i:numsDivide){ GCD=__gcd(GCD,i); }
        for(int i=0; i<nums.size(); i++){
            if(GCD%nums[i]==0){ return i; }
        }
        return -1;
    }
};