class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        map<double,int> m;
        for(int i=0; i<c.size(); i++){
            for(int j=i+1; j<c.size(); j++){
                double slope;
                if(c[j][0]==c[i][0]){ slope=0; }
                else slope=(c[j][1]-c[i][1])/(c[j][0]-c[i][0]);
                m[slope]++;
            }
        }
        return m.size()==1;
    }
};