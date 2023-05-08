class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat[0].size();
        int ans=0;
        int i=0, j=0;
        while(i<n){ ans+=mat[i++][j++]; }
        i=0; j=n-1;
        while(i<n){ ans+=mat[i++][j--]; }
        if(n%2){ return ans-mat[n/2][n/2]; }
        return ans;
    }
};