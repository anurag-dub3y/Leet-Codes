class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length(), curr=0;
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1; i<n; i++){
            if(i>=minJump){ curr+=dp[i-minJump]; }
            if(i>maxJump){ curr-=dp[i-maxJump-1]; }
            dp[i]=curr>0 and s[i]=='0';
        }
        return dp[n-1];
    }
};