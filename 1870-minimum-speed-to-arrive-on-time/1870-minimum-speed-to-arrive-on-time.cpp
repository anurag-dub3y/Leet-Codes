class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        auto check=[&](const int& mid){
            double timeReq=0.0;
            for(int i=0; i<dist.size(); i++){
                timeReq+=(1.0*dist[i])/mid;
                if(i!=dist.size()-1){ timeReq=ceil(timeReq); }
            }
            return timeReq<=hour;
        };
        double ans=-1, low=1, hi=1e7+1;
        while(hi>=low){
            int mid=(hi+low)/2;
            if(check(mid)){
                ans=mid;
                hi=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};