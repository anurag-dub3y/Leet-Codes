class Solution {
public:
    // vector<string> splitMessage(string &m, int limit) {
        // int n=m.length();
        // auto digits=[&](const int &val){
        //     return 1+log10(val);
        // };
        // auto check=[&](const int &mid){
        //     int parts=0, i=0, d2=digits(mid);
        //     if(d2+d2+3>=mid){ return false; }
        //     while(i<m){
        //         
        //     }
        //     return parts==mid;
        // };
        // int low=1, high=n;
        // while(low<=high){
        //     int mid=(low+high)/2;
        //     if(check(mid)){ low=mid+1; }
        //     else{ high=mid-1; }
        // }
        // high is the optimal number of sections
        vector<string> splitMessage(string &s, int limit) {
            int n = s.length();
            auto sz=[&](int n) {
                return to_string(n).length();
            };
            int parts = 1, a = 1;
            while(a + n + parts * (3 + sz(parts)) > parts * limit) {
                if(3 + sz(parts) * 2 >= limit){ return {}; }
                parts++;
                a+=sz(parts);
            }
            vector<string> ans;
            int count = 1;
            for(int i = 0; i < n; ) {
                string q = "<" + to_string(count++) + "/" + to_string(parts) + ">";
                string p="";
                for(int j = 0; j < limit - q.size() && i < n; j++){ p += s[i++]; }
                p += q;
                ans.push_back(p);
            }
            return ans;
        }
};