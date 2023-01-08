class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(), ans=0;
        for(int i=0; i<n; i++){
            unordered_map<string,int> counter;      // for hashing points with a slope
            int numDupl=1;
            for(int j=i+1; j<n; j++){       // key is the slope of point b/w pnt i and j
                if(points[j][0]==points[i][0] && points[j][1]==points[i][1]){ numDupl++; }
                else{
                    int dx=points[j][0]-points[i][0], dy=points[j][1]-points[i][1];
                    int g=__gcd(dx,dy);         // this is how slope is calculated
                    counter[to_string(dx/g)+'_'+to_string(dy/g)]++;     // storing the slope as double may cause problems due to division thats why we are making it a string
                }
            }
            ans = max(ans, numDupl);
            for (auto p : counter) {
                ans = max(ans, p.second + numDupl);
            }
        }
        return ans;
    }
};