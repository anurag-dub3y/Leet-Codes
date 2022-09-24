class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n + 1, 0);
        vector<int> right(n + 1, 0);
        int r_pos = n + 1;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                r_pos = i;
            }
            else if (dominoes[i] == 'L') {
                r_pos = n + 1;
            }
            left[i] = r_pos == n + 1 ? n + 1 : i - r_pos;
        }
        int l_pos = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                l_pos = i;
            }
            else if (dominoes[i] == 'R') {
                l_pos = -1;
            }
            right[i] = l_pos == -1 ? n + 1 : l_pos - i;
        }
        
        string result = dominoes;
        for (int i = 0; i < n; ++i) {
            if (left[i] < right[i]) result[i] = 'R';
            else if (left[i] > right[i]) result[i] = 'L';
        }

        return result;
    } 
};