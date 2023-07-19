class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_set<int> mp;
        for(int i=0; i<A.size(); i++){
            mp.insert(A[i]); 
            int cnt=0;
            for(int j=0; j<=i; j++){
                if(mp.count(B[j])){ cnt++; }    
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};