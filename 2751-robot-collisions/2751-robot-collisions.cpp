class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string &dir) {
        for(int i=0; i<h.size(); i++){ if(dir[i]=='L'){ h[i]=-h[i]; } }
        vector<vector<int>> vp;
        for(int i=0; i<h.size(); i++){ vp.push_back({pos[i],h[i],i}); }
        sort(begin(vp),end(vp));
        stack<pair<int,int>> st;
        for(int i=0; i<h.size(); i++){
            if(vp[i][1]>0){
                st.push({vp[i][2],vp[i][1]});
            }
            else{
                int flag=0;
                while(!st.empty() and st.top().second>0 and flag==0){
                    pair<int,int> r=st.top(); st.pop();
                    if(r.second>0){
                        if(abs(vp[i][1])<r.second){ 
                            r.second--; 
                            if(r.second>0){ st.push({r.first,r.second}); flag=1; }
                        }
                        else if(abs(vp[i][1])>r.second){
                            vp[i][1]++;
                            if(vp[i][1]==0){ flag=1;  }
                        }
                        else{ flag=1; break; }
                    }
                }
                if(!flag){ 
                    st.push({vp[i][2],vp[i][1]}); 
                }
            }
        }
        vp.clear();
        while(!st.empty()){ vp.push_back({st.top().first,abs(st.top().second)}); st.pop(); }
        vector<int> ans;
        sort(begin(vp),end(vp));
        for(auto &i:vp){ ans.push_back(i[1]); }
        return ans;
    }
};