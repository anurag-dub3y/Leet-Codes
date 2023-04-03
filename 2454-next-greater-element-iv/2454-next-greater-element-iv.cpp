class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int> st;
        multiset<vector<int>> s;
        int n=nums.size();
        vector<int> ans(n,-1);
        st.push(0);
        for(int i=1; i<n; i++){
            while(!s.empty() and nums[i]>(*s.begin())[0]){
                ans[(*s.begin()).back()]=nums[i];
                s.erase(s.begin());
            }
            while(!st.empty() and nums[i]>nums[st.top()]){
                s.insert({nums[st.top()],st.top()});
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};