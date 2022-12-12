class Solution {
public:
    vector<int> bit;
    void update(int x){
        while(x<100001){
            bit[x]++; x+=(x&-x);
        }
    }
    int get(int x){
        int r=0;
        while(x>0){
            r+=bit[x]; 
            x-=(x&-x);
        }
        return r;
    }
    int createSortedArray(vector<int>& in) {
        bit.resize(100001,0);
        int ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < in.size(); ++i) {
            ans = (ans + min(get(in[i] - 1), i - get(in[i]))) % mod;
            update(in[i]);
        }
        return ans;
    }
};