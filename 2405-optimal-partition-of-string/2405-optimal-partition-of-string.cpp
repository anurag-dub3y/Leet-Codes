class Solution {
public:
    int partitionString(string s) {
        map<char,int> m;
        int ans=1;
        for(int i=0; i<s.length(); i++){
            if(m[s[i]]){
                m.clear();
                ans++;
            }
            m[s[i]]++;
        }
        return ans;
    }
};