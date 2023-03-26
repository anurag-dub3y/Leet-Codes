class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        vector<int> r;
        while(numOnes--){ r.push_back(1); }
        while(numZeros--){ r.push_back(0); }
        while(numNegOnes--){ r.push_back(-1); }
        int i=0, ans=0;
        while(k--){ ans+=r[i++]; }
        return ans;
    }
};