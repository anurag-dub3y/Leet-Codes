class Solution {
public:
    int maxVowels(string s, int k) {
        int vowels[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
        int ans = 0, cnt=0;
        for(int i = 0; i < s.size(); i++) {
            cnt += vowels[s[i] - 'a'];
            if(i >= k) cnt -= vowels[s[i - k] - 'a'];
            ans = max(ans, cnt);
        }
        return ans;
    }
};