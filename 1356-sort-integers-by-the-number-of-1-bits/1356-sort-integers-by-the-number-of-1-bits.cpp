class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr),end(arr),[&](int a, int b){
            int x=__builtin_popcount(a), y=__builtin_popcount(b);
            return x!=y?x<y:a<b;
        });
        return arr;
    }
};