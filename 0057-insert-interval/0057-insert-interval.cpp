class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& newInt) {
        ints.push_back(newInt);
        sort(ints.begin(),ints.end());
        vector<vector<int>> ans;
        int a=ints[0][0], b=ints[0][1];
        for(int i=1; i<ints.size(); i++){
            if(ints[i][0]>b){
                ans.push_back({a,b});
                a=ints[i][0]; b=ints[i][1];
            }
            else{ b=max(ints[i][1],b); }
        }
        ans.push_back({a,b});
        return ans;
    }
};