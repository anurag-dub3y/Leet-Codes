class Solution {
public:
    int minimumPartition(string s, int k) {
        int n=s.length(), ans=0, i=0; long long prev=0;
        while(i<n){
            if(s[i]-'0'>k){ return -1; }
            prev+=(s[i]-'0');
            if(prev>k){ prev=(s[i]-'0'); ++ans; }
            prev*=10;
            i++;
        }
        return ans+1;
    }
};