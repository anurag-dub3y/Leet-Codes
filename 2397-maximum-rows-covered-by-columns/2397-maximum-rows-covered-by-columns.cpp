class Solution {
public:

    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int>hsh(n);          
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] & 1)
                    hsh[i] |= (1 << j);
        int mask = (1 << m) - 1;
        int ans = 0;
        for(int sub = mask; sub; sub = (sub - 1) & mask) {
            if(__builtin_popcount(sub) == numSelect) {
                int curr = 0;
                for(const int &a: hsh)
                    if((a & sub) == a)
                        curr++;
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};