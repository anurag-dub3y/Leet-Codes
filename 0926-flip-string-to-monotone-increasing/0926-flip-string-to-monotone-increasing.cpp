class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans=0, ones=0;
        for(auto i:s){
            if(i=='1'){ ones++; }
            else{
                ans=min(ans+1,ones);
            }
        }
        return ans;
    }
};