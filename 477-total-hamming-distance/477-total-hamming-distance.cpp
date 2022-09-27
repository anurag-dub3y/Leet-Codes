class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int bit=0; bit<32; bit++){
            int cnt0=0, cnt1=0;
            for(auto i:nums){
                if((1<<bit)&i){ cnt1++; }
                else{ cnt0++; }
            }
            ans+=cnt1*cnt0;
        }
        return ans;
    }
};