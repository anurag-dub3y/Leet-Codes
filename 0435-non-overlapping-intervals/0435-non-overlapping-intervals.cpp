class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ints) {
        sort(begin(ints),end(ints),[&](const vector<int> &a, const vector<int> &b){
            if(a[1]!=b[1]){ return a[1]<b[1]; }
            return a[0]>b[0];
        });
        int end=ints[0][1], ans=0;
        for(int i=1; i<ints.size(); i++){
            if(ints[i][0]>=end){ end=ints[i][1]; }
            else{ ans++; }
        }
        return ans;
    }
};