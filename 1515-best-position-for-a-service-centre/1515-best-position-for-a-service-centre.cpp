class Solution {
public:
    
    double computeDistances(double x, double y, vector<vector<int>>& positions) {
        double total = 0;
        for(int i = 0; i < positions.size(); i++) {
            total += sqrt(
                (x - positions[i][0]) * (x - positions[i][0]) + 
                (y - positions[i][1]) * (y - positions[i][1]));
        }
        
        return total;
    }
    
    double search(double y, vector<vector<int>>& positions) {
        
        double lo = 0;
        double hi = 100;
        
        for(int i = 0; i < 100; i++) {
            double part = (hi - lo) / 3;
            double q1 = lo + part;
            double q2 = hi - part;
            
            double d1 = computeDistances(q1, y, positions);
            double d2 = computeDistances(q2, y, positions);
            
            if(d1 < d2) {
                hi = q2;
            } else if(d1 > d2) {
                lo = q1;
            } else {
                lo = q1;
                hi = q2;
            }
        }
        
        return min(computeDistances(lo, y, positions), computeDistances(hi, y, positions));
    }
    
    double getMinDistSum(vector<vector<int>>& positions) {
        
        
        double lo = 0;
        double hi = 100;
        
        for(int i = 0; i < 100; i++) {
            double part = (hi - lo) / 3;
            double q1 = lo + part;
            double q2 = hi - part;
            
            double d1 = search(q1, positions);
            double d2 = search(q2, positions);
            
            if(d1 < d2) {
                hi = q2;
            } else if(d1 > d2) {
                lo = q1;
            } else {
                lo = q1;
                hi = q2;
            }
        }
        
        return min(search(lo, positions), search(hi, positions));
    }
};