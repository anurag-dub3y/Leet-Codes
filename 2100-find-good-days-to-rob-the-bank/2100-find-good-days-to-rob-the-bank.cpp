class Solution {
public:
    // security = s
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        int n=s.size();
        vector<int> prev(n,1), suff(n,1);
        for(int i=1; i<n; i++){
            if(s[i]<=s[i-1]){ prev[i]=1+prev[i-1]; }
        }
        for(int i=n-2; i>=0; i--){
            if(s[i]<=s[i+1]){ suff[i]=1+suff[i+1]; }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(prev[i]-1>=time && suff[i]-1>=time){ ans.push_back(i); }
        }
        return ans;
    }
};