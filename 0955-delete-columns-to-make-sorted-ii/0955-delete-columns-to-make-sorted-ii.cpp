class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // auto check=[&](string &s){
        //     map<char,int> mp;
        //     for(auto &i:s){ mp[i]++; if(mp[i]>1){ return false; } }
        //     return true;
        // };
        // int n=strs[0].length();
        // vector<string> v(n);
        // for(auto &s:strs){
        //     for(int i=0; i<n; i++){
        //         v[i]+=s[i];
        //     }
        // }
        // int ans=0;
        // for(auto &s:v){
        //     int v1=is_sorted(begin(s),end(s)), v2=check(s);
        //     if(v1 and v2){
        //         return ans;
        //     }
        //     else if(!v1){
        //         ans++;
        //     }
        // }
        // return ans;
        unordered_set<int> delCol;
        for(int i=1; i<strs.size(); i++){
            for(int j = 0; j<strs[i].length(); j++){
                if(delCol.count(j) or strs[i-1][j]==strs[i][j]){ continue; }
                if(strs[i-1][j]>strs[i][j]) {
                    delCol.insert(j);
                    i = 0;
                }
            break;
            }
        }
    return delCol.size();
    }
};
