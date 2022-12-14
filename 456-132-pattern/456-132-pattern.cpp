class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int minYet=INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]<minYet){ return true; }
            while(!st.empty() && nums[i]>st.top()){
                minYet=st.top(); st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};