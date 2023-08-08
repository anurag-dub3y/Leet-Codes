class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> v1, v2;
        for(int i = 0; i < (n>>1) + (n&1); i++){
            v1.push_back(nums[i]);
        }
        for(int i = (n>>1); i < n; i++){
            v2.push_back(nums[i]);
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        int s1 = 0, s2 = 0;
        for(int i= 0; i < n; i++){
            if(i&1){ nums[i] = v2[s2++]; }
            else nums[i] = v1[s1++];
        }
    }
};