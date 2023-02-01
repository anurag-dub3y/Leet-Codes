class Solution {
public:
    string gcdOfStrings(string& s, string& t){
        return (s+t==t+s)?s.substr(0, gcd(s.length(),t.length())): "";
    }
};