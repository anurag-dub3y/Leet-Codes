class Solution {
public:
    int mod=1e9+7;
    int dp[100005][3][3][2];
    int find(int n, int x, int y, int absentYet){
        if(n==0){ return 1; }
        if(dp[n][x][y][absentYet]!=-1){
            return dp[n][x][y][absentYet];
        }
        long long ans=0LL;
        
        // Present 
        if(x==0){
            ans=(1LL*ans+find(n-1,0,0,absentYet))%mod;
            if(absentYet==0){
                ans=(1LL*ans+find(n-1,1,0,1))%mod;
            }
            ans=(1LL*ans+find(n-1,2,0,absentYet))%mod;
        }
        
        // Absent
        if(x==1){
            ans=(1LL*ans+find(n-1,0,1,1))%mod;
            ans=(1LL*ans+find(n-1,2,1,1))%mod;
        }
        
        // Late
        if(x==2){
            ans=(1LL*ans+find(n-1,0,2,absentYet))%mod;
            if(absentYet==0){
                ans=(1LL*ans+find(n-1,1,2,1))%mod;
            }
            if(y!=2){
                ans=(1LL*ans+find(n-1,2,2,absentYet))%mod;
            }
        }
        return dp[n][x][y][absentYet]=ans%mod;
    }
    // int find()
    int checkRecord(int n) {
        if(n==1){ return 3; }
        memset(dp,-1,sizeof(dp));
        long long ans1=(1LL*find(n-2,0,0,0)+find(n-2,0,1,1)+find(n-2,0,2,0))%mod;
        long long ans2=(1LL*find(n-2,1,0,1)+find(n-2,1,2,1))%mod;
        long long ans3=(1LL*find(n-2,2,0,0)+find(n-2,2,1,1)+find(n-2,2,2,0))%mod;
        return (ans1+ans2+ans3)%mod;
    }
};