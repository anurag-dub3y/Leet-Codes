class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int x=count(begin(s),end(s),'0');
        int y=count(begin(s),end(s),'1');
        string ans="";
        while(y>1){
            y--;
            ans+='1';
        }
        while(x--){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};