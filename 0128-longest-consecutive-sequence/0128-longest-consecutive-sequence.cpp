class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=0, prev, curr=1;
        for(auto &it:nums){
            if(ans==0){ prev=it; }
            else if(it==prev+1){ curr++; }
            else if(it==prev){ continue; }
            else if(it!=prev+1){ curr=1; }
            ans=max(ans,curr);
            prev=it;
        }
        return ans;
    }
};