class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> st;
        int ans=abs(nums[x]-nums[0]);
        for(int i=x; i<nums.size(); i++){
            st.insert(nums[i-x]);
            auto it=st.upper_bound(nums[i]);
            if(it!=st.end()){ ans=min(ans,abs(*it-nums[i])); }
            if(it!=st.begin()){ ans=min(ans,abs(*prev(it)-nums[i])); }
        }
        return ans; 
    }
};