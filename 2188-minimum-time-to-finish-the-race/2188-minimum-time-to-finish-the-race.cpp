class Solution {
public:
    int dp[1001], mxVal=0;
    long long find(map<int,int> &tires, int changeTime, int numLaps){
        if(numLaps==0){ return 0; }
        if(dp[numLaps]!=-1){ return dp[numLaps]; }
        long long ans=LLONG_MAX;
        for(auto &[t0,t1]:tires){
            long long curr=0;
            for(int i=numLaps; i>0; i--){
                long long largeVal=1LL*t0*pow(t1,numLaps-i);
                if(largeVal>changeTime+mxVal){ break; }
                curr+=1LL*t0*pow(t1,numLaps-i);
                if(i==1){
                    ans=min(ans,1LL*curr+find(tires,changeTime,0));
                }
                else{
                    ans=min(ans,1LL*changeTime+curr+find(tires,changeTime,i-1));
                }
            }
        }
        return dp[numLaps]=ans;
    }
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        memset(dp,-1,sizeof(dp));
        map<int,int> realTires;
        for(auto &t:tires){
            if(realTires.count(t[0])==0){ realTires[t[0]]=t[1]; }
            else{ realTires[t[0]]=min(realTires[t[0]],t[1]); }
            mxVal=max(mxVal,t[0]);
        }
        // for(auto &[t0,t1]:realTires){ cout<<t0<<' '<<t1<<endl; }
        return (int)find(realTires,changeTime,numLaps);
    }
};