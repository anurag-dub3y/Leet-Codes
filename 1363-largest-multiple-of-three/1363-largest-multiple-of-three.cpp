class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int m1[] = {1, 4, 7, 2, 5, 8}, m2[] = {2, 5, 8, 1, 4, 7};
        int sum = 0, ds[10] = {};  
        for (auto d : digits) {
            ds[d]++;
            sum += d;
        }
        while (sum % 3 != 0) {
          for (auto i : sum % 3 == 1 ? m1 : m2) {
            if (ds[i]) {
              ds[i]--;
              sum -= i;
              break;
            }
          }
        }
        string ans="";
        for (int i=9; i>=0; --i)
          ans += string(ds[i], '0'+i);
        return (ans.size() && ans[0]=='0')? "0" : ans;
    }
};