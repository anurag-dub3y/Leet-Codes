class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size(), n=strs[0].length();
        vector<string> v(n,"");
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                v[j]+=strs[i][j];
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(!is_sorted(v[i].begin(),v[i].end())){ ++ans; }
        }
        return ans;
    }
};