class Solution {
public:
    int maxIncreasingGroups(vector<int>& u) {
        // sort(rbegin(u),rend(u));
        // if(u[0]==u.back()){ return u[0]; }
        // auto check=[&](const int &mid){
        //     for(int i=0; i<u.size(); i++){
        //         if(u[i]<mid-i){ return false; }
        //     }
        //     return true;
        // };
        // int low=0, high=u.size();
        // while(low<=high){
        //     int mid=(low+high)>>1;
        //     if(check(mid)){ low=mid+1; }
        //     else{ high=mid-1; }
        // }
        // return high;
        sort(begin(u),end(u));
        long long curr=0, cnt=0;
        for(auto &i:u){
            curr+=i;
            if(curr>=(cnt+1)*(cnt+2)/2){ cnt++; }
        }
        return cnt;
    }
};