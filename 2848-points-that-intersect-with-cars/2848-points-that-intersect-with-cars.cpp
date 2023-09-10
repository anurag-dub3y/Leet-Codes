class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> st;
        for(auto &i:nums){
            for(int j=i[0]; j<=i[1]; j++){
                st.insert(j);
            }
        }
        return st.size();
    }
};