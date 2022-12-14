class Solution {
public:
    int findIntegers(int n) {
        if(n<3){ return n+1; }
        vector<int> dp(32,0);
        dp[0]=1, dp[1]=2;
        
        // 111111... = (dp(n)) can be broken down into 01111... = dp(n-1) with 0 prefix + 10111... = dp(n-2) 2ith 10 prefix
        for(int i=2; i<32; i++){ dp[i]=dp[i-1]+dp[i-2]; }
        int maxBit=30;
        while(n&(1<<maxBit)==0){ maxBit--; }
        int ans=0, prevBit=0, k=maxBit;
        while(k>=0){
            if(n&(1<<k)){
                ans+=dp[k]; // if kth bit is set then dp[k] is the number of valid numbers (we have unse the k+1 th bit) 
                if(prevBit==1){ return ans; }   // if number is ...11.... type the we return current value
                prevBit=1;
            }
            else{ prevBit=0; }
            k--;
        }
        return ans+1;   // including the number itself
    }
};

