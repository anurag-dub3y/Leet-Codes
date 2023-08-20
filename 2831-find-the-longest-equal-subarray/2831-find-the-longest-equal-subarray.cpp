class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> inds;
        for(int i=0; i<nums.size(); i++){
            inds[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto &[num,it]:inds){
            int i=0, j=0, cnt=0;
            while(i<it.size()){
                while(it[i]-it[j]-cnt>k){ j++; cnt--; }
                cnt++;
                ans=max(ans,cnt);
                i++;
            }
        }
        return ans;
    }
};