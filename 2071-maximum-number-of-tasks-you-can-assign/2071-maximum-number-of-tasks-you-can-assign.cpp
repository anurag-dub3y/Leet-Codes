class Solution {
public:
    // int maxTaskAssign(vector<int>& t, vector<int>& w, int p, int s) {
    //     int n=t.size(), m=w.size();
    //     sort(begin(t),end(t));
    //     sort(rbegin(w),rend(w));
    //     auto check1=[&](int mid){
    //         int i=0, j=0, p_dash=p;
    //         while(i<mid){
    //             if(t[i]>w[j]){
    //                 if(p_dash==0 or t[i]>w[j]+s){ return false; }
    //                 p_dash--;
    //             }
    //             i++; j++;
    //         }
    //         return true;
    //     };
    //     auto check2=[&](int mid){
    //         int i=0, j=mid-1, p_dash=p;
    //         while(i<mid){
    //             if(t[i]>w[j]){
    //                 if(p_dash==0 or t[i]>w[j]+s){ return false; }
    //                 p_dash--;
    //             }
    //             i++; j--;
    //         }
    //         return true;
    //     };
    //     auto check3=[&](int mid){
    //         int i=mid-1, j=0, p_dash=p;
    //         while(i>=0){
    //             if(t[i]>w[j]){
    //                 if(p_dash==0 or t[i]>w[j]+s){ return false; }
    //                 p_dash--;
    //             }
    //             i--; j++;
    //         }
    //         return true;
    //     };
    //     auto check4=[&](int mid){
    //         int i=mid-1, j=mid-1, p_dash=p;
    //         while(i>=0){
    //             if(t[i]>w[j]){
    //                 if(p_dash==0 or t[i]>w[j]+s){ return false; }
    //                 p_dash--;
    //             }
    //             i--; j--;
    //         }
    //         return true;
    //     };
    //     auto greedy=[&](int mid){
    //         int p_dash=p;
    //         multiset<int> ms(begin(w),end(w));
    //         for(int i=mid-1; i>=0; i--){
    //             // auto it=ms.rbegin();
    //             auto it=prev(ms.end());
    //             if(*it>=t[i]){
    //                 ms.erase(it);
    //             }
    //             else{
    //                 auto lb=ms.lower_bound(t[i]-s);
    //                 if(lb==ms.end() or p_dash<0){ return false; }
    //                 p_dash--;
    //                 ms.erase(lb);
    //             }
    //         }
    //         return true;
    //     };
    //     int mn=0, mx=min(m,n);
    //     while(mn<=mx){
    //         int md=(mn+mx)/2;
    //         // if(check1(md) or check2(md) or check3(md) or check4(md)){ mn=md+1; }
    //         if(greedy(md)){ mn=md+1; }
    //         else{ mx=md-1; }
    //     }
    //     return mx;
    // }
    int maxTaskAssign(vector<int>& tasks, vector<int>& ws, int pills, int strength) {
        int l = 0, r = min(tasks.size(), ws.size());
        sort(begin(tasks), end(tasks));
        sort(begin(ws), end(ws));
        while (l < r) {
            int m = (l + r + 1) / 2, need = 0;
            multiset<int> ms(end(ws) - m, end(ws));
            for (int i = m - 1; i >= 0; --i) {
                auto it = prev(end(ms));
                if (*it < tasks[i]) {
                    it = ms.lower_bound(tasks[i] - strength);
                    if (it == end(ms) || ++need > pills)
                        break;
                }
                ms.erase(it);
            }
            if (ms.empty()) l = m;
            else r = m - 1;
        }
        return l;
    }
};