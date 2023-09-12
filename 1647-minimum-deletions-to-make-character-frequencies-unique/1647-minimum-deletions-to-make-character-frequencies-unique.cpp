class Solution {
public:
    int minDeletions(string s) {
        map<char,int> m;
        for(auto &i:s){ m[i]++; }
        vector<pair<char,int>> vp;
        for(auto &p:m){ vp.push_back(p); }
        sort(begin(vp),end(vp),[&](auto &p1, auto &p2){ return p1.second<p2.second; } );
        set<int> st;
        for(int i=1; i<=s.length(); i++){ st.insert(i); }
        int ans=0;
        st.erase(vp[0].second);
        for(int i=1; i<vp.size(); i++){
            if(vp[i].second==vp[i-1].second){
                int mn=*st.lower_bound(vp[i].second);
                if(mn!=*st.begin()){
                    mn=min(mn,*prev(st.lower_bound(vp[i].second)));
                }
                if(mn<vp[i].second){
                    ans+=vp[i].second-mn;
                    st.erase(mn);
                }
                else{ ans+=vp[i].second; }
            }
            else{
                st.erase(vp[i].second);
            }
        }
        return ans;
    }
};