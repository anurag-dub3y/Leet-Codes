class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,double> m;
        long long ans=0;
        for(auto r:rectangles){
            double ratio=(1.0*r[0])/(1.0*r[1]);
            // cout<<ratio<<endl;
            if(m.find(ratio)!=m.end()){
                ans+=m[ratio];
            }
            m[ratio]+=1;
        }
        return ans;
    }
};
//