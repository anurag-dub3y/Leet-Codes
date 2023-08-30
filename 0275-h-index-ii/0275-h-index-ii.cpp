class Solution {
public:
    int hIndex(vector<int>& c) {
        int low=0, high=c.back();
        while(low<=high){
            int mid=(low+high)/2;
            int sz=c.size()-(lower_bound(begin(c),end(c),mid)-begin(c));
            if(sz>=mid){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};