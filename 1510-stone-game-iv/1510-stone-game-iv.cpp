class Solution {
public:
    int dp[100005][2];
    int find(int n, int alice){
        if(n==0){ return alice==0; }
        int &val=dp[n][alice];
        if(val!=-1){ return val; }
        if(alice==1){
            val=0;
            for(int i=1; i*i<=n; i++){
                val=val|find(n-i*i,0);
            }
        }
        else{
            val=1;
            for(int i=1; i*i<=n; i++){
                val=val&find(n-i*i,1);
            }
        }
        return val;
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n,1);
    }
};