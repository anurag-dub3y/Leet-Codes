class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int as=a.size(), bs=b.size();
        int i=as-1,j=bs-1;
        int carry=0;
         while(i>=0 || j>=0 || carry){
            if(i>=0){
                carry += a[i] - '0';
                i--;
            }
            if(j>=0){
                carry += b[j] - '0';
                j--;
            }
            
            c += (carry%2 + '0');
            carry = carry/2;
        }
        reverse(begin(c),end(c));
        return c;
    }
};