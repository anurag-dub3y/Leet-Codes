class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        for(int i=0; i<nums.size()/2; i++){
            string s1=to_string(nums[i]), s2=to_string(nums[nums.size()-i-1]);
            ans+=stoll(s1+s2);
        }
        if(nums.size()%2==1){ ans+=nums[nums.size()/2]; }
        return ans;
    }
};