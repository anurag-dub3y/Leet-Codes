class Solution {
public:
    int findMinMoves(vector<int>& mch) {
        int n=mch.size(), sum=accumulate(begin(mch),end(mch),0);
        if(sum%n!=0){ return -1; }
        int avg = sum / n;
        vector<int> leftSums(n,0), rightSums(n,0);
        for(int i=1; i<n; i++) { leftSums[i] = leftSums[i-1]+mch[i-1]; }
        for(int i=n-2; i>=0; i--){ rightSums[i] = rightSums[i+1]+mch[i+1]; }
        int moves=0;
        for(int i=0; i<n; i++){
            int expLeft=i*avg, expRight=(n-i-1)*avg;
            int left=0, right=0;
            if(expLeft>leftSums[i]){ left = expLeft-leftSums[i]; } 
            if(expRight>rightSums[i]){ right = expRight-rightSums[i]; }
            moves = max(moves, left+right);
        }
        return moves;
    }
};