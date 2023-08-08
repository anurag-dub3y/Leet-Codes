class Solution {
public:
    int characterReplacement(string s, int k) {
        set<char> chars(begin(s),end(s));
        int n=s.length(), ans=k;
        for(auto &c:chars){
            int curr=0, left=0, right=0, diff=0;
            while(right<n){
                if(s[right]==c){ curr++; }
                else{ diff++; }
                while(diff>k){
                    if(s[left]==c){ curr--; }
                    else{ diff--; }
                    left++;
                }
                right++;
                ans=max(right-left,ans);
            }
        }
        return ans;
    }
};