class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int res = 0;
        for(int i = 0, j = s.length() - 1; i < s.length() / 2; i++, j--) {
            if(s[i] == s[j]) continue;
            int f = j - 1;
            for(; f >= i; f--) { //find closest character
                if(s[i] == s[f]) break;
            }
            if(f == i) { //if closest character is at s[i], s[i] should move to middle of s
                res += s.length() / 2 - i;
                j++;
            } else { //else, calculate distance and swap all characters
                res += j - f;
                for(; f < j; f++) {
                    swap(s[f], s[f+1]);
                }
            }
        }
        return res;
    }
};