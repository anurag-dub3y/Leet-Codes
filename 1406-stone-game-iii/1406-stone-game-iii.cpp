class Solution {
public:
    int n;
    int dp[50001][2];
    int search(int ind, int x, vector<int>& stone){
        if(ind>=n){ return 0; }
        if(dp[ind][x]!=-1){ return dp[ind][x]; }
        if(x==1){
            int i1=stone[ind]+search(ind+1,0,stone),
                i2=ind<n-1?stone[ind]+stone[ind+1]+search(ind+2,0,stone):(int)-1e9,
                i3=ind<n-2?stone[ind]+stone[ind+1]+stone[ind+2]+search(ind+3,0,stone):(int)-1e9;
            return dp[ind][x]=max({i1,i2,i3});
        }
        else{
            int i1=-stone[ind]+search(ind+1,1,stone),
                i2=ind<n-1?-stone[ind]-stone[ind+1]+search(ind+2,1,stone):(int)1e9,
                i3=ind<n-2?-stone[ind]-stone[ind+1]-stone[ind+2]+search(ind+3,1,stone):(int)1e9;
            return dp[ind][x]=min({i1,i2,i3});
        }
    }
    string stoneGameIII(vector<int>& stone) {
        n=stone.size();
        memset(dp,-1,sizeof(dp));
        int ans=search(0,1,stone);
        if(ans>0){ return "Alice"; }
        else if(ans==0){ return "Tie"; }
        return "Bob";
    }
};