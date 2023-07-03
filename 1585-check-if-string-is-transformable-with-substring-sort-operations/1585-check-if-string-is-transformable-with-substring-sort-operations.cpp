class Solution {
public:
//     Passed 134/138 TCs
//     map<string,bool> dp;
//     int n;
//     bool check1(string S, string t){
//         string s=S;
//         bool ans1=false;
//         int i=0;
//         while(i<n and s[i]==t[i]){ i++; }
//         int j=i;        // we need to bring some s[j] here
//         char mn=s[j];
//         while(j<n and s[j]!=t[i]){
//             mn=min(mn,s[j]);
//             j++;
//             // if(j!=n and s[j]>t[i]){ return false; }
//         }
//         if(j==n or mn<t[i]){ return false; }
//         sort(s.begin()+i,s.begin()+j+1);
//         return ans1|=isTransformable(s,t); 
//     }
//     bool check2(string S, string t){
//         string s=S;
//         int x=n-1;
//         while(x>=0 and s[x]==t[x]){ x--; }
//         int y=x;
//         char mx=s[y];
//         while(y>=0 and s[y]!=t[x]){ mx=max(s[y],mx); y--; }
//         if(y<0 or mx>t[x]){ return false; }
//         // cout<<s.substr(y,x-y+1)<<endl;
//         sort(s.begin()+y,s.begin()+x+1);
//         return isTransformable(s,t);
//     }
//     bool isTransformable(string s, string t) {
//         if(s==t){ return true; }
//         n=s.length();
//         string temp=s+'#'+t;
//         if(dp.count(temp)){ return dp[temp]; }
//         // cout<<s<<' '<<t<<endl;
        
//         return dp[temp]=check1(s,t) or check2(s,t);
//     }
    bool isTransformable(string &s, string &t) {
        int n=s.length();
        map<int,deque<int>> mp;
        for(int i=0; i<n; i++){
            mp[s[i]-'0'].push_back(i);
        }
        for(int i=0; i<n; i++){
            int num=t[i]-'0';
            if(mp.count(num)==0 or mp[num].size()==0){ return false; }
            for(int j=0; j<num; j++){
                if(mp.count(j) and !mp[j].empty() and mp[j].front()<mp[num].front()){ return false; }
            }
            mp[num].pop_front();
        }
        return true;
    }
};