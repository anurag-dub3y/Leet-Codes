class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        unordered_map<int,unordered_map<int,int>> u;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                u[i-j][mat[i][j]]++;
            }
        }
        for(auto i:u){
            if(i.second.size()>1){ return false; }
        }
        return true;
    }
};