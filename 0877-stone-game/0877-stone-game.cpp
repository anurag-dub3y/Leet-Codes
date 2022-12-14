class Solution {
public:
    map<vector<int>,int> dp;
    int search(int l, int r, vector<int>& stone, int x){
        if(r>l){ return 0; }
        if(dp.find({l,r,x})!=dp.end()){ return dp[{l,r,x}]; }
        return dp[{l,r,x}] = max(x?stone[l]:-stone[l]+search(l+1,r,stone,x^1),x?stone[r]:-stone[r]+search(l,r-1,stone,x^1)); 
    }
    bool stoneGame(vector<int>& stone) {
        int n=stone.size();
        int x=search(0,n-1,stone,1);
        return (dp[{0,n-1,1}]>=0);
    }
};