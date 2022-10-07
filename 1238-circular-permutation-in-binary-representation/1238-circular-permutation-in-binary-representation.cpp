class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> OG;
        int ind;
        for(int i=0; i<(1<<n); i++){
            int val = i^(i>>1);
            if(val==start){ ind=i; }
            OG.push_back(val);
        }
        int sz=1<<n;
        vector<int> ans;
        for(int i=0; i<sz; i++){
            ans.push_back(OG[(i+ind)%sz]);
        }
        return ans;
    }
};