class Solution {
public:
    int dp[10004];
    int racecar(int target) {
        // cout<<target<<endl;
        if(dp[target]>0){ return dp[target]; }
        int maxBit=1+floor(log2(target));
        // The car reaches (1<<maxBit)-1 and reverses, the remaining subproblem is equal to 
        if(1<<maxBit==target+1){ dp[target]=maxBit; }
        
        else{
            dp[target]=racecar((1<<maxBit)-1-target)+maxBit+1;
            //  The car reaches 1<<(maxBit-1)-1 and then reverses, accelerates for another b steps 
            // in the opposite direction and reverses again. Now its position is at 2^(maxBit-1) - 2^b, 
            // the remaining subproblem is to go from current position to i with initial speed, 
            // which is dp[i-2^(maxBit-1)+2^b].
            for(int b=0; b<maxBit-1; b++){
                int x=(1<<(maxBit-1)), y=(1<<b);
                cout<<target<<' '<<x<<' '<<y<<endl;
                dp[target]=min(dp[target],racecar(target-x+y)+maxBit+b+1);
            }
        }
        return dp[target];
    }
};

