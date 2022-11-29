class Solution {
public:
    int fact[9]={1,1,2,6,24,120,720,5040,40320};
    double haveSame=0, total=0, totalBalls;
    void backtrack(int first, int second, vector<int>& balls, int distinct1, int distinct2, int ind, double p1, double p2){
        if(ind==balls.size()){
            total+=(double)p1*p2; 
            if(distinct1==distinct2){ haveSame+=(double)p1*p2; } 
            return;
        }
        for(int j=0; j<=balls[ind]; j++){
            if(first+j<=totalBalls/2 and second+balls[ind]-j<=totalBalls/2){
                // j balls of [ind] kind go to the first box and rest to the second box
                // if j==0 then first box doesn't get any new distinct ball
                // if j==balls[ind] then second box doesn't get any new distinct ball
                if(j==0){                 
                    backtrack(first,second+balls[ind],balls,distinct1,distinct2+1,
                          ind+1,p1/fact[j],p2/fact[balls[ind]-j]);
                }
                else if(j==balls[ind]){
                    backtrack(first+j,second,balls,distinct1+1,distinct2,ind+1,p1/fact[j],p2/fact[balls[ind]-j]);
                }
                else{ backtrack(first+j,second+(balls[ind]-j),balls,distinct1+1,distinct2+1,ind+1,p1/fact[j],p2/fact[balls[ind]-j]); }
            }
        }
    }
    double factorial(int n){
        return n<3?n:n*factorial(n-1);
    }
    double getProbability(vector<int>& balls) {
        totalBalls=accumulate(balls.begin(),balls.end(),0);
        int first=0, second=0, distinct1=0, distinct2=0;
        backtrack(first,second,balls,distinct1,distinct2,0,factorial(totalBalls/2),factorial(totalBalls/2));
        double ans = (1.0*haveSame)/(1.0*total);
        return ans;
    }
};