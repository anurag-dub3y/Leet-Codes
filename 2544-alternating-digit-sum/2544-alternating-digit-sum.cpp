class Solution {
public:
    int alternateDigitSum(int n) {
        string s=to_string(n);
        int ans=0;
        for(int i=0; i<s.length(); i++){
            ans+=i%2==0?(s[i]-'0'):-(s[i]-'0');
        }
        return ans;
    }
};