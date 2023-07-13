class Solution {
public:
    int find(long cur, int bitmask, int& N){
        // cout<<cur<<' ';
        if(cur > N) return 0;
        int ans=1;
        for(int digit=0; digit<10; digit++){
            if(bitmask == 0 && digit == 0){ continue; }
            if((bitmask & (1<<digit))){ continue; } // has repeat digits
            ans=ans+find(cur*10 + digit, bitmask | (1<<digit), N);
        }
        return ans;
    }
    int numDupDigitsAtMostN(int N) {
        int uniqueDigits=find(0,0, N);
        // cout<<endl;
        return N - uniqueDigits + 1; // +1 as 0 is counted
    }
};