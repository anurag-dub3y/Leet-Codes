class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<int> v;
        v.push_back(t[0][0]);
        for(int i=1; i<n; i++){
            vector<int> g; 
            g.push_back(v[0]+t[i][0]);
            for(int r=1; r<t[i].size()-1; r++){
                g.push_back(t[i][r]+min(v[r],v[r-1]));
            }
            g.push_back(v.back()+t[i].back());
            swap(v,g);
        }
        return *min_element(v.begin(),v.end());
    }
};