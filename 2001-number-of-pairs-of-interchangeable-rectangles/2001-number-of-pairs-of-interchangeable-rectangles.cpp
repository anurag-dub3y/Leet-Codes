class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,double> m;
        long long ans=0;
        for(auto r:rectangles){
            double ratio=(1.0*r[0])/(1.0*r[1]);
            m[ratio]+=1;
        }
        for(auto [a,b]:m){
            ans+=1LL*b*(b-1)/2;
        }
        return ans;
    }
};
//