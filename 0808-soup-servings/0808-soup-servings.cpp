map<pair<int,int>,double> dp;
class Solution {
public:
    double find(int a, int b){
        if(a==0 and b==0){ return 0.5; }
        else if(a==0){ return 1.0; }
        else if(b==0){ return 0; }
        pair<int,int> p={a,b};
        if(dp.count(p)){ return dp[p]; }
        double ans=0.0;
        for(int i=0; i<4; i++){
            ans+=0.25*find(max(0.0,1.0*a-(4-i)*25),max(0.0,1.0*b-25*i));
        }
        return dp[p]=ans;
    }
    double soupServings(int n) {
        if(n>4801){ return 1.0; }
        return find(n,n);
    }
};