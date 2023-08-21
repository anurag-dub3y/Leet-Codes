class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& ints) {
        int ans=0;
        for(int i=0; i<ints.size(); i++){
            for(int j=0; j<ints.size(); j++){
                if(j==i){ continue; }
                if(ints[i][0]>=ints[j][0] and ints[i][1]<=ints[j][1]){ ans++; break; }                
            }
        }
        return ints.size()-ans;
    }
};