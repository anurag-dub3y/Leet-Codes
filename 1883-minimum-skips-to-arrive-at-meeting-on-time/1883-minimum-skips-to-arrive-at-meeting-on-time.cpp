class Solution {
public:
    vector<vector<double>> dp;
    double run(int i, int skips, vector<int>& dist, int speed){
        if(skips<0){ return DBL_MAX; }
        if(i==dist.size()){ return 0; }
        if(dp[i][skips]!=DBL_MAX){ return dp[i][skips]; }
        double time=1.0*dist[i]/speed;
        double restedTime=ceil(run(i+1,skips,dist,speed)+time-1e-09), unrestedTime=run(i+1,skips-1,dist,speed)+time;
        return dp[i][skips]=min(restedTime,unrestedTime);
    }
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n=dist.size();
        dp = vector<vector<double>>(n+1, vector<double>(n+1, DBL_MAX));
        for(int skips=0; skips<dist.size(); skips++){
            if(run(0,skips,dist,speed)<=hoursBefore){ return skips; }
        }
        return -1;
    }
};