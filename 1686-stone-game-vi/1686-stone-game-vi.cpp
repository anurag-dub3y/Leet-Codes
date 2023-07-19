class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<vector<int>> vp;
        for(int i=0; i<a.size(); i++){
            vp.push_back({a[i]+b[i],a[i],b[i]});
        }
        sort(rbegin(vp),rend(vp));
        int cnt1=0, cnt2=0;
        for(int i=0; i<a.size(); i++){
            if(i%2==0){ cnt1+=vp[i][1]; }
            else{ cnt2+=vp[i][2]; }
        }
        if(cnt1==cnt2){ return 0; }
        return (cnt1-cnt2)/abs(cnt1-cnt2);
    }
};