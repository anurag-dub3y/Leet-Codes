class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // if(accumulate(nums.begin(),nums.end(),0)%k==0 && nums.size()>)
        unordered_map<int,int> m;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            if((m.find(sum%k)!=m.end() && i-m[sum%k]>=2) or (i>=1 && sum%k==0)){ return true; }
            else if(m.find(sum%k)==m.end()){ m[sum%k]=i; }
        }
        return false;
    }
};

