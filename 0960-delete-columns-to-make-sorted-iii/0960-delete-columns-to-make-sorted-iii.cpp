class Solution {
public:
    bool comp(vector<string> &s, int i, int j){
        for(int k=0; k<s.size(); k++){
            if(s[k][i]<s[k][j]){ return false; }
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size(), n=strs[0].length();
        vector<int> dp(n,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(comp(strs,i,j)){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return n-*max_element(begin(dp),end(dp));
    }
};