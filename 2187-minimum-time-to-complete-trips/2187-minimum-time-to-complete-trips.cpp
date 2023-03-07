#define ll long long
class Solution {
public:
    ll minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        ll l=1, r=1e14;
        while(l<r){
            ll mid = l + (r-l)/2;
            ll trips=0;
            for(int i=0; i<time.size(); i++){
                trips+=(mid/(ll)time[i]);    
            }
            if(trips>=totalTrips){ r=mid; }
            else{ l=mid+1; }
        }
        return l;
    }
};