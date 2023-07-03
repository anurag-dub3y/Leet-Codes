class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](const vector<int> &t1, const vector<int> &t2){
            // if(t1[1]!=t2[1]){ return t1[1]>t2[1]; }
            // return t1[0]<t2[0];
            return t1[1]-t1[0]>t2[1]-t2[0];
        });
        // auto check=[&](int mid){
        //     int ans=mid;
        //     for(auto t:tasks){
        //         if(ans<t[1]){ return false; }
        //         ans-=t[0];
        //     }
        //     return true;
        // };
        // int mn=0, mx=1e8, ans;
        // while(mn<=mx){
        //     int mid=(mn+mx)/2;
        //     cout<<mid<<' ';
        //     if(!check(mid)){ mn=mid+1; }
        //     else{ ans=mid; mx=mid-1; }
        // }
        // return ans;
        int ans=0, curr=0;
        for(auto t:tasks){
            if(curr<t[1]){
                int borrow=t[1]-curr;
                ans+=borrow;
                curr+=borrow;
            }
            curr-=t[0];
        }
        return ans;
    }
};