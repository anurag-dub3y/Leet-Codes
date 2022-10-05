class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k){
        if(k==nums.size()){ return nums; }
        stack<int> st;
        st.push(nums[0]);
        for(int i=1; i<nums.size(); i++){
            while(!st.empty() && st.top()>nums[i] && st.size()-1+nums.size()-i>= k){ st.pop(); }
            if(st.size()<k){ st.push(nums[i]); }
        }
        // while(st.size()>k){ st.pop(); }
        vector<int> ans;
        while(!st.empty()){ ans.push_back(st.top()); st.pop(); }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};