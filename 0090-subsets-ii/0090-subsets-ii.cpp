class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size=1LL<<nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        for(int i=0; i<size; i++){
            vector<int> sub;
            for(int r=0; r<nums.size(); r++){
                if(i&(1<<r)){ sub.push_back(nums[r]); }
            }
            st.insert(sub);
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};