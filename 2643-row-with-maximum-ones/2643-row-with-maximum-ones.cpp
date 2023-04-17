class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans={0,0};
        for(int i=0; i<mat.size(); i++){
            int cnt=count(begin(mat[i]),end(mat[i]),1);
            if(cnt>ans.back()){
                ans={i,cnt};
            }
        }
        return ans;
    }
};