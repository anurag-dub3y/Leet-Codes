class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans ; 
        int size = B.size();
        multiset<int> st;
        for(int i = 0; i< size; i++){
            st.insert(A[i]);
        }
        for(int i = 0; i<size; i++){
            auto upper1 = st.upper_bound(B[i]);
            if(upper1 != st.end()){
                ans.push_back(*upper1);
                st.erase(upper1);
            }
            else{
                ans.push_back(*st.begin());
                st.erase(st.begin());
            }
        }
        return ans;
    }
};