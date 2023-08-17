class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        unordered_map<int,int> onesRow, onesCol;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[0].size(); j++){
                if(g[i][j]==1){
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }
        int m=g.size(), n=g[0].size();
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[0].size(); j++){
                int a=(onesRow.count(i))?onesRow[i]:0;
                int b=(onesCol.count(j))?onesCol[j]:0;
                g[i][j]=a+b-(n-a)-(m-b);
            }
        }
        return g;
    }
};